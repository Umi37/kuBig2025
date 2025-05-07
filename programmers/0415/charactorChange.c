#include <stdio.h>
#include <string.h>
#define LEN_INPUT 100

int main(void) {
    char s1[LEN_INPUT];
    char s2[LEN_INPUT];

    scanf("%s", s1);

    int len = strlen(s1);
    
    for (int i = 0; i < len; i++) {
        char ch = s1[i];
        if (ch >= 'A' && ch <= 'Z') {
            s2[i] = ch + 32; // 대문자 → 소문자
        } else if (ch >= 'a' && ch <= 'z') {
            s2[i] = ch - 32; // 소문자 → 대문자
        } else {
            s2[i] = ch; // 알파벳이 아니면 그대로
        }
    }

    s2[len] = '\0';  // 문자열 끝을 꼭 닫아줘야 함!

    printf("%s\n", s2);

    return 0;
}
