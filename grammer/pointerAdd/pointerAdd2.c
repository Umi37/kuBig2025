#include <stdio.h>

int main(void) {
    char *s1 = "Hello";
    char *s2 = "Hello";

    printf("s1: %s at %p\n", s1, s1);
    printf("s2: %s at %p\n", s2, s2);

    if (s1 == s2) {
        printf("s1 and s2 point to the SAME address.\n");
    } else {
        printf("s1 and s2 point to DIFFERENT addresses.\n");
    }

    return 0;
}
