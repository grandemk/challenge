#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/mman.h>
#include <unistd.h>
char *str1 = "\x5e\x78\x73\x2a\x6b\x6d\x6b\x63\x64\x2a\x24\x24\x24";
char *str2= "\x53\x65\x7f\x2a\x7d\x63\x64\x2b";

void no_no_no(void) __attribute__((constructor));

void no_no_no(void)
{
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1) 
    {
        printf("don't try to debug me !!\n");
        //exit(1);
    }
}

void get_msg(char **msg)
{
    for (int i = 0; i < strlen(*msg); ++i)
        (*msg)[i] ^= 10;
}

unsigned char check_f[371] = {0x71,
    0xad, 0xc1, 0xa7, 0xc8, 0x0c, 0x85, 0x04, 0x95, 0x2a, 0x2c,
    0xa7, 0xc8, 0x28, 0x74, 0xcc, 0x08, 0x00, 0x25, 0x24, 0xa7,
    0xe0, 0x34, 0xa7, 0xe4, 0x25, 0xa7, 0xc8, 0x28, 0x74, 0xcc,
    0x79, 0xdb, 0x24, 0x24, 0xa7, 0xe0, 0x34, 0xad, 0x61, 0xcc,
    0x85, 0x00, 0x95, 0x2a, 0x2c, 0xa7, 0xc8, 0x28, 0x74, 0xcc,
    0x2d, 0x00, 0x25, 0x24, 0xa7, 0xe0, 0x34, 0xa7, 0xe4, 0x25,
    0xa7, 0xc8, 0x28, 0x74, 0xcc, 0x1e, 0xdb, 0x24, 0x24, 0xa7,
    0xe0, 0x34, 0xad, 0x61, 0xc0, 0xe3, 0x61, 0xd4, 0x57, 0x25,
    0x24, 0x24, 0xaf, 0x61, 0xc8, 0xe2, 0x24, 0x41, 0xaf, 0x61,
    0xc8, 0xa7, 0xe4, 0x25, 0xe2, 0x24, 0x48, 0xaf, 0x61, 0xc8,
    0xa7, 0xe4, 0x26, 0xe2, 0x24, 0x7b, 0xaf, 0x61, 0xc8, 0xa7,
    0xe4, 0x27, 0xe2, 0x24, 0x42, 0xaf, 0x61, 0xc8, 0xa7, 0xe4,
    0x20, 0xe2, 0x24, 0x48, 0xaf, 0x61, 0xc8, 0xa7, 0xe4, 0x21,
    0xe2, 0x24, 0x45, 0xaf, 0x61, 0xc8, 0xa7, 0xe4, 0x22, 0xe2,
    0x24, 0x43, 0xaf, 0x61, 0xc8, 0xa7, 0xe4, 0x23, 0xe2, 0x24,
    0x4a, 0xaf, 0x61, 0xc8, 0xa7, 0xe4, 0x2c, 0xe2, 0x24, 0x45,
    0xaf, 0x61, 0xc8, 0xa7, 0xe4, 0x2d, 0xe2, 0x24, 0x40, 0xaf,
    0x61, 0xc8, 0xa7, 0xe4, 0x2e, 0xe2, 0x24, 0x45, 0xaf, 0x31,
    0x04, 0x95, 0x2a, 0x2c, 0xaf, 0x61, 0xcc, 0xa7, 0xc8, 0x2c,
    0x76, 0x74, 0xcc, 0xbe, 0xd0, 0xdb, 0xdb, 0xa7, 0xe0, 0x34,
    0xaf, 0x31, 0x00, 0x95, 0x2a, 0x2c, 0xaf, 0x61, 0xc0, 0xa7,
    0xc8, 0x2c, 0x76, 0x74, 0xcc, 0xa0, 0xd0, 0xdb, 0xdb, 0xa7,
    0xe0, 0x34, 0xa7, 0xc8, 0x28, 0xdb, 0x51, 0x2c, 0xcc, 0x72,
    0x07, 0x25, 0x24, 0xa7, 0xe0, 0x34, 0xad, 0xe6, 0xaf, 0x61,
    0xd4, 0x1d, 0xe6, 0x51, 0x70, 0xe3, 0x61, 0xd0, 0x24, 0x24,
    0x24, 0x24, 0xcf, 0x3a, 0xaf, 0x71, 0xd0, 0xaf, 0x61, 0xc8,
    0x25, 0xf4, 0x2b, 0x92, 0x34, 0xaf, 0x69, 0xd0, 0xaf, 0x61,
    0x2c, 0x25, 0xec, 0x2b, 0x92, 0x24, 0x1c, 0xe6, 0x51, 0x10,
    0xa7, 0x61, 0xd0, 0x25, 0xaf, 0x61, 0xd0, 0x1f, 0x61, 0xd4,
    0x58, 0xfe, 0xa7, 0xc8, 0x28, 0xa9, 0x61, 0xc0, 0x74, 0xcc,
    0xa7, 0xda, 0xdb, 0xdb, 0xa7, 0xe0, 0x34, 0xaf, 0x61, 0xc0,
    0xa7, 0xc8, 0x28, 0x74, 0xcc, 0x24, 0x41, 0x24, 0x24, 0xa7,
    0xe0, 0x34, 0x9c, 0x24, 0x24, 0x24, 0x24, 0xcf, 0x03, 0xb4,
    0xcf, 0x25, 0xb4, 0xa7, 0xc8, 0x28, 0xa9, 0x61, 0xcc, 0x74,
    0xcc, 0x7e, 0xda, 0xdb, 0xdb, 0xa7, 0xe0, 0x34, 0xaf, 0x61,
    0xcc, 0xa7, 0xc8, 0x28, 0x74, 0xcc, 0xf3, 0x40, 0x24, 0x24,
    0xa7, 0xe0, 0x34, 0x9c, 0x25, 0x24, 0x24, 0x24, 0xed, 0xe7,
};

int check(char *argv)
{
    char *error_msg = malloc(strlen(str1) + 1);
    char *win_msg = malloc(strlen(str2) + 1);
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

    strcpy(error_msg, str1);
    strcpy(win_msg, str2);
    if (strlen(argv) != pass_size)
        goto fail;

    for (int i = 0; i < pass_size; ++i)
        if (pass[i] != argv[i])
            goto fail;

    get_msg(&win_msg);
    printf("%s\n", win_msg);
    return 0;
fail:
    get_msg(&error_msg);
    printf("%s\n", error_msg);
    return 1;

}

void create_check(void *vaddr)
{
    char *check_fcn = (char *)vaddr;
    for (int i = 0; i < 371; ++i)
        check_fcn[i] = check_f[i] ^ '$';
}

int check2(char *argv, void *vaddr)
{
    int (*check_fcn) (char *argv) = (int (*)(char *argv)) vaddr;
    check_fcn(argv);
}

int bcheck(char *argv)
{
    unsigned long fcn = (unsigned long)&check;
    unsigned long vaddr = fcn / sysconf(_SC_PAGESIZE) * sysconf(_SC_PAGESIZE);
    size_t size = 400 + fcn % sysconf(_SC_PAGESIZE);
    int ret;

    ret = mprotect((void *)vaddr, size, PROT_READ | PROT_WRITE | PROT_EXEC);
    if (ret != 0) {
        perror("bcheck");
        return 1;
    }

    // create_check(&check_f);
    check2(argv, (void *)fcn);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

    return bcheck(argv[1]);
}


