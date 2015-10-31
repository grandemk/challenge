#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/mman.h>
#include <unistd.h>
// %uncomment% #include "check2.c"
#define check_f l// %del%

char *l;

void no_no_no(void) __attribute__((constructor));

void no_no_no(void)
{
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1)
    {
        printf("don't try to debug me !!\n");
        exit(1);
    }
}

void get_msg(char **msg)
{
    for (int i = 0; i < strlen(*msg); ++i)
        (*msg)[i] ^= 10;
}

void my_strcpy(char *s1, char *s2)
{
    strcpy(s1, s2);
}

int my_strlen(char *s)
{
    return strlen(s);
}

void my_printf(char *fmt, char *msg)
{
    printf(fmt, msg);
}

char *my_malloc(size_t size)
{
    return malloc(size);
}

// %uncomment% #if 0
int check(char *argv, char *str1, char *str2) __attribute__((section (".check_section")));
int check(char *argv, char *str1, char *str2)
{
    char *error_msg = my_malloc(my_strlen(str1) + 1);
    char *win_msg = my_malloc(my_strlen(str2) + 1);
    char msg[4] = {'%', 's','\n', 0};
    int pass_size = 7;
    char pass[11];
    pass[0] = 'e';
    pass[1] = 'l';
    pass[2] = '_';
    pass[3] = 'f';
    pass[4] = 'l';
    pass[5] = 'a';
    pass[6] = 'g';
    pass[7] = 'n';
    pass[8] = 'a';
    pass[9] = 'd';
    pass[10] = 'a';

    my_strcpy(error_msg, str1);
    my_strcpy(win_msg, str2);
    if (my_strlen(argv) != pass_size)
        goto fail;

    for (int i = 0; i < pass_size; ++i)
        if (pass[i] != argv[i])
            goto fail;

    get_msg(&win_msg);
    my_printf(msg, win_msg);
    return 0;
fail:
    get_msg(&error_msg);
    my_printf(msg, error_msg);
    return 1;

}
// %uncomment% #endif

void create_check(void *vaddr)
{
    char *check_fcn = (char *)vaddr;
    for (int i = 0; i < sizeof(check_f); ++i)
        check_fcn[i] = check_f[i] ^ '$';
}

int check2(char *argv, void *vaddr)
{
    int (*check_fcn) (char *argv, char *str1, char *str2) = (int (*)(char *argv, char *str1, char * str2)) vaddr;
    char *str1 = "\x5e\x78\x73\x2a\x6b\x6d\x6b\x63\x64\x2a\x24\x24\x24";
    char *str2= "\x53\x65\x7f\x2a\x7d\x63\x64\x2b";
    check_fcn(argv, str1, str2);
}

int bcheck(char *argv)
{
    unsigned long fcn = (unsigned long)&check_f;
    unsigned long vaddr = fcn / sysconf(_SC_PAGESIZE) * sysconf(_SC_PAGESIZE);
    size_t size = 400 + fcn % sysconf(_SC_PAGESIZE);
    int ret;

    ret = mprotect((void *)vaddr, size, PROT_READ | PROT_WRITE | PROT_EXEC);
    if (ret != 0) {
        perror("bcheck");
        return 1;
    }

    create_check(&check_f);
    check2(argv, (void *)fcn);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

    return bcheck(argv[1]);
}


