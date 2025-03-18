#include <stdio.h>

int main(void)
{
    char ch;
    char str[100];

    printf("문자를 입력하세요 : ");
    ch = getc(stdin); //블록킹이 된다? 무슨의미
    printf("입력한 문자눈 %c 입니다.", ch);
    ch = getchar();

    ch = getchar(); // getc 를쓰나 똑같음?
    printf("입력한 문자는 %c 입니다.", ch);
    scanf("%s", str);
    printf("입력한 문자는 %s 입니다.", str);
    // 버퍼에 개행 문자가 있다.
    getchar();
    return 0;
}