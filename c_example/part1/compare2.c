//1과 9 사이의 숫자인지 확인해서 맞으면 1 틀리면 0을 프린트 하세요

#include <stdio.h>

int main(void)
{
    int a ; // 변수 선언
    printf("숫자를 넣으세요 1~9:  ");
    scanf("%d", &a); // 숫자 입력

    printf("1 <= %d <= 9 : %d\n", a, (1 <= a) && ( a <= 9)) ;
    return 0;

}