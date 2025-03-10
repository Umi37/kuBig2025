#include <stdio.h>

int main() {
    int a;
    double b;
    char c;

    printf("Size of int: %lu bytes\n", sizeof(a));
    printf("Size of double: %lu bytes\n", sizeof(b));
    printf("Size of char: %lu bytes\n", sizeof(c));


    printf("Size of int: %d bytes\n", sizeof(a));
    printf("Size of double: %d bytes\n", sizeof(b));
    printf("Size of char: %d bytes\n", sizeof(c));

    int aa = 293489238498;
    double bb = 2.3357825;
    char cc = "Aaaaaaaaa";

    printf("Size of int: %lu bytes\n", sizeof(a));
    printf("Size of double: %lu bytes\n", sizeof(b));
    printf("Size of char: %lu bytes\n", sizeof(c));

    return 0;
}
