#include <stdio.h>

int main(void) {
    char *s = "Hello";
    printf("1. s points to: %s at %p\n", s, s);

    s = "Hi";
    printf("2. s now points to: %s at %p\n", s, s);

    s = "Hello";
    printf("3. s returns to: %s at %p\n", s, s);

    return 0;
}
