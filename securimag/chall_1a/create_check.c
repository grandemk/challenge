#include <stdio.h>

int main(void)
{
    printf("unsigned char check_f[%i] = {\n", _BUFFER_SIZE);
    for (int i=0; i < _BUFFER_SIZE; ++i) {
        buffer[i] ^= '$';
        printf("0x%02x, ", buffer[i]);
        if (i % 11 == 10)
            printf("\n");
    }
    printf("};");


}

