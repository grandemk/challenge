#define _BUFFER_SIZE 371
#include <stdio.h>
unsigned char check_f[371] = {
    0x55, 0x89, 0xe5, 0x83, 0xec, 0x28, 0xa1, 0x20, 0xb1, 0x0e, 0x08, 
    0x83, 0xec, 0x0c, 0x50, 0xe8, 0x2c, 0x24, 0x01, 0x00, 0x83, 0xc4, 
    0x10, 0x83, 0xc0, 0x01, 0x83, 0xec, 0x0c, 0x50, 0xe8, 0x5d, 0xff, 
    0x00, 0x00, 0x83, 0xc4, 0x10, 0x89, 0x45, 0xe8, 0xa1, 0x24, 0xb1, 
    0x0e, 0x08, 0x83, 0xec, 0x0c, 0x50, 0xe8, 0x09, 0x24, 0x01, 0x00, 
    0x83, 0xc4, 0x10, 0x83, 0xc0, 0x01, 0x83, 0xec, 0x0c, 0x50, 0xe8, 
    0x3a, 0xff, 0x00, 0x00, 0x83, 0xc4, 0x10, 0x89, 0x45, 0xe4, 0xc7, 
    0x45, 0xf0, 0x73, 0x01, 0x00, 0x00, 0x8b, 0x45, 0xec, 0xc6, 0x00, 
    0x65, 0x8b, 0x45, 0xec, 0x83, 0xc0, 0x01, 0xc6, 0x00, 0x6c, 0x8b, 
    0x45, 0xec, 0x83, 0xc0, 0x02, 0xc6, 0x00, 0x5f, 0x8b, 0x45, 0xec, 
    0x83, 0xc0, 0x03, 0xc6, 0x00, 0x66, 0x8b, 0x45, 0xec, 0x83, 0xc0, 
    0x04, 0xc6, 0x00, 0x6c, 0x8b, 0x45, 0xec, 0x83, 0xc0, 0x05, 0xc6, 
    0x00, 0x61, 0x8b, 0x45, 0xec, 0x83, 0xc0, 0x06, 0xc6, 0x00, 0x67, 
    0x8b, 0x45, 0xec, 0x83, 0xc0, 0x07, 0xc6, 0x00, 0x6e, 0x8b, 0x45, 
    0xec, 0x83, 0xc0, 0x08, 0xc6, 0x00, 0x61, 0x8b, 0x45, 0xec, 0x83, 
    0xc0, 0x09, 0xc6, 0x00, 0x64, 0x8b, 0x45, 0xec, 0x83, 0xc0, 0x0a, 
    0xc6, 0x00, 0x61, 0x8b, 0x15, 0x20, 0xb1, 0x0e, 0x08, 0x8b, 0x45, 
    0xe8, 0x83, 0xec, 0x08, 0x52, 0x50, 0xe8, 0x9a, 0xf4, 0xff, 0xff, 
    0x83, 0xc4, 0x10, 0x8b, 0x15, 0x24, 0xb1, 0x0e, 0x08, 0x8b, 0x45, 
    0xe4, 0x83, 0xec, 0x08, 0x52, 0x50, 0xe8, 0x84, 0xf4, 0xff, 0xff, 
    0x83, 0xc4, 0x10, 0x83, 0xec, 0x0c, 0xff, 0x75, 0x08, 0xe8, 0x56, 
    0x23, 0x01, 0x00, 0x83, 0xc4, 0x10, 0x89, 0xc2, 0x8b, 0x45, 0xf0, 
    0x39, 0xc2, 0x75, 0x54, 0xc7, 0x45, 0xf4, 0x00, 0x00, 0x00, 0x00, 
    0xeb, 0x1e, 0x8b, 0x55, 0xf4, 0x8b, 0x45, 0xec, 0x01, 0xd0, 0x0f, 
    0xb6, 0x10, 0x8b, 0x4d, 0xf4, 0x8b, 0x45, 0x08, 0x01, 0xc8, 0x0f, 
    0xb6, 0x00, 0x38, 0xc2, 0x75, 0x34, 0x83, 0x45, 0xf4, 0x01, 0x8b, 
    0x45, 0xf4, 0x3b, 0x45, 0xf0, 0x7c, 0xda, 0x83, 0xec, 0x0c, 0x8d, 
    0x45, 0xe4, 0x50, 0xe8, 0x83, 0xfe, 0xff, 0xff, 0x83, 0xc4, 0x10, 
    0x8b, 0x45, 0xe4, 0x83, 0xec, 0x0c, 0x50, 0xe8, 0x00, 0x65, 0x00, 
    0x00, 0x83, 0xc4, 0x10, 0xb8, 0x00, 0x00, 0x00, 0x00, 0xeb, 0x27, 
    0x90, 0xeb, 0x01, 0x90, 0x83, 0xec, 0x0c, 0x8d, 0x45, 0xe8, 0x50, 
    0xe8, 0x5a, 0xfe, 0xff, 0xff, 0x83, 0xc4, 0x10, 0x8b, 0x45, 0xe8, 
    0x83, 0xec, 0x0c, 0x50, 0xe8, 0xd7, 0x64, 0x00, 0x00, 0x83, 0xc4, 
    0x10, 0xb8, 0x01, 0x00, 0x00, 0x00, 0xc9, 0xc3, };
int main(void)
{
    printf("unsigned char check_f[371] = {");
    for (int i=0; i<_BUFFER_SIZE; ++i) {
        check_f[i] ^= '$';
        printf("0x%02x, ", check_f[i]);
        if (i % 10 == 0)
            printf("\n");
    }
    printf("};");


}
