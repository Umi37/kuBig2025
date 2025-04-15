#include <stdio.h>
#include <string.h>

int main() {
    const char *haystack = "Hello, world!";
    const char *needle = "world";

    // strstr 호출
    const char *result = strstr(haystack, needle);

    if (result != NULL) {
        printf("찾은 문자열: %s\n", result);
        printf("(haystack) 주소 : %p\n", (void *)haystack);
        printf("(result) 주소 : %p\n", (void *)result);
        printf("(world) 주소 - %p\n", (void *)needle);
        printf("문자열 내 오프셋 위치      : %ld\n", result - haystack);
    } else {
        printf("문자열을 찾을 수 없습니다.\n");
    }

    return 0;
}
