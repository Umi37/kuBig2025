#include <stdio.h>

int main(void)
{
    int a,b, temp;
    a = 10;
    b = 10;

    // swap
    temp = a;
    a = b;
    b = temp;

    printf("a = %d, b = %d", a, b);
    return 0;
}