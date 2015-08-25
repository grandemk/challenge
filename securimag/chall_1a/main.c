#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/mman.h>
#include <unistd.h>

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


unsigned char check_f[325] __attribute__ ((section (".check_section"))) = {
    0x71, 0xad, 0xc1, 0xa7, 0xc8, 0x0c, 0xa7, 0xc8, 0x28, 0xdb, 0x51, 
    0x28, 0xcc, 0x5a, 0x27, 0x24, 0x24, 0xa7, 0xe0, 0x34, 0xa7, 0xe4, 
    0x25, 0xa7, 0xc8, 0x28, 0x74, 0xcc, 0xbb, 0x27, 0x24, 0x24, 0xa7, 
    0xe0, 0x34, 0xad, 0x61, 0xc8, 0xa7, 0xc8, 0x28, 0xdb, 0x51, 0x34, 
    0xcc, 0x7a, 0x27, 0x24, 0x24, 0xa7, 0xe0, 0x34, 0xa7, 0xe4, 0x25, 
    0xa7, 0xc8, 0x28, 0x74, 0xcc, 0x5b, 0x27, 0x24, 0x24, 0xa7, 0xe0, 
    0x34, 0xad, 0x61, 0xcc, 0xe2, 0x61, 0xc0, 0x01, 0xe2, 0x61, 0xc1, 
    0x57, 0xe2, 0x61, 0xc2, 0x2e, 0xe2, 0x61, 0xc3, 0x24, 0xe3, 0x61, 
    0xd4, 0x23, 0x24, 0x24, 0x24, 0xe2, 0x61, 0xfd, 0x41, 0xe2, 0x61, 
    0xfe, 0x48, 0xe2, 0x61, 0xff, 0x7b, 0xe2, 0x61, 0xf8, 0x42, 0xe2, 
    0x61, 0xf9, 0x48, 0xe2, 0x61, 0xfa, 0x45, 0xe2, 0x61, 0xfb, 0x43, 
    0xe2, 0x61, 0xc4, 0x4a, 0xe2, 0x61, 0xc5, 0x45, 0xe2, 0x61, 0xc6, 
    0x40, 0xe2, 0x61, 0xc7, 0x45, 0xaf, 0x61, 0xc8, 0xa7, 0xc8, 0x2c, 
    0xdb, 0x51, 0x28, 0x74, 0xcc, 0xf9, 0x26, 0x24, 0x24, 0xa7, 0xe0, 
    0x34, 0xaf, 0x61, 0xcc, 0xa7, 0xc8, 0x2c, 0xdb, 0x51, 0x34, 0x74, 
    0xcc, 0xef, 0x26, 0x24, 0x24, 0xa7, 0xe0, 0x34, 0xa7, 0xc8, 0x28, 
    0xdb, 0x51, 0x2c, 0xcc, 0xf3, 0x26, 0x24, 0x24, 0xa7, 0xe0, 0x34, 
    0x1f, 0x61, 0xd4, 0x51, 0x7c, 0xe3, 0x61, 0xd0, 0x24, 0x24, 0x24, 
    0x24, 0xcf, 0x3a, 0xa9, 0x71, 0xfd, 0xaf, 0x61, 0xd0, 0x25, 0xf4, 
    0x2b, 0x92, 0x34, 0xaf, 0x69, 0xd0, 0xaf, 0x61, 0x2c, 0x25, 0xec, 
    0x2b, 0x92, 0x24, 0x1c, 0xe6, 0x51, 0x1c, 0xa7, 0x61, 0xd0, 0x25, 
    0xaf, 0x61, 0xd0, 0x1f, 0x61, 0xd4, 0x58, 0xfe, 0xa7, 0xc8, 0x28, 
    0xa9, 0x61, 0xcc, 0x74, 0xcc, 0x0a, 0x26, 0x24, 0x24, 0xa7, 0xe0, 
    0x34, 0xaf, 0x61, 0xcc, 0xa7, 0xc8, 0x2c, 0x74, 0xa9, 0x61, 0xc0, 
    0x74, 0xcc, 0xb3, 0x26, 0x24, 0x24, 0xa7, 0xe0, 0x34, 0x9c, 0x24, 
    0x24, 0x24, 0x24, 0xcf, 0x0f, 0xb4, 0xcf, 0x25, 0xb4, 0xa7, 0xc8, 
    0x28, 0xa9, 0x61, 0xc8, 0x74, 0xcc, 0x25, 0x26, 0x24, 0x24, 0xa7, 
    0xe0, 0x34, 0xaf, 0x61, 0xc8, 0xa7, 0xc8, 0x2c, 0x74, 0xa9, 0x61, 
    0xc0, 0x74, 0xcc, 0x4e, 0x26, 0x24, 0x24, 0xa7, 0xe0, 0x34, 0x9c, 
    0x25, 0x24, 0x24, 0x24, 0xed, 0xe7, };

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

//int check(char *argv, char *str1, char *str2) __attribute__((section (".check_section")));
#if 0
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
#endif

void create_check(void *vaddr)
{
    char *check_fcn = (char *)vaddr;
    for (int i = 0; i < 371; ++i)
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


