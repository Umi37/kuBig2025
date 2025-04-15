#include <stdio.h>
#include <string.h>

int main() {
    const char *haystack = "Hello, world!";
    const char *needle = "world";

    const char *result = strstr(haystack, needle);

    if (result != NULL) {
        printf("찾은 문자열: %s\n", result);
        printf("(haystack) 주소 : %p\n", (void *)haystack);
        printf("(result) 주소   : %p\n", (void *)result);
        printf("(needle) 주소   : %p\n", (void *)needle);

        printf("\n--- 주소 간격 계산 ---\n");
        printf("result - haystack : %ld 바이트\n", result - haystack);
        printf("needle - result   : %ld 바이트\n", needle - result);
        printf("needle - haystack : %ld 바이트\n", needle - haystack);
    }

    return 0;
}
