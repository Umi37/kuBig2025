#include <limits.h>
#include <stdio.h> //standard input, output drag F12

int main(void)
{
    printHello();
    printf("char_bit : %d\n", CHAR_BIT);
    printf("char_max : %d\n", CHAR_MAX);
    printf("INT_MIN : %d \n INT_MAX : %d\n", INT_MIN, INT_MAX);
    printf("LONG_MIN : %ld \n LONG_MAX : %ld\n", LONG_MIN, LONG_MAX);
    printf("INT_MAX + 1 : %d\n", INT_MAX + 1);
    return 0;
}

void printHello()
{
    printf("hello, world\n");
}