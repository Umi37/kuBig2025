#include <stdio.h>

int main(void)
{
    char *name; //캐릭터 포인트
    char namei[20];
    name = namei;
    *name = 'h';
    *(name + 1) = 'e';
    *(name + 2) = 'l';
    *(name + 3) = 'l';
    *(name + 4) = 'o';
    *(name + 5) = '\0';
    *(name + 6) = 's'; // NULL문자 전까지만 출력되고 뒤쪽은 무시됨
    *(name + 7) = 'u';
    *(name + 8) = 'n';

    printf("%s\n", name);
    return 0;
}