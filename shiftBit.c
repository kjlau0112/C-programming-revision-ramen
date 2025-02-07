#include <stdio.h>

//1 byte 8 bits
//4 byte 32 bit
//unsigned int 32 bits

void print_binary(unsigned int num) {
    for (int i = sizeof(unsigned int)*8 -1 ; i >= 0; i--) {  // Print only 8 bits
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    unsigned int num = 5;
    printf("Before shifting: ");
    print_binary(num);

    num = num << 1;
    printf("After shifting:  ");
    print_binary(num);
b
    num = num>>1;
    printf("After right shifting 1 bit:  ");
    print_binary(num);


    printf("Decimal result: %u\n", num);
    return 0;
}