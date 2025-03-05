// 정수를 두 숫자를 받아서 크기 관계 0 과 1 로 프린트 하기

#include <stdio.h>

int main(void)
{
    int a, b; // 먼저 변수를 선언
    int greater ;
    printf("두 정수를 입력하세요\n : ");
    scanf("%d %d", &a,&b);

    greater = a > b; //비교연산자의 결과는 0 또는 1이다. 참이면 1, 거짓이면 0
    printf("greater 의 값은 %d 이다.", greater);
    

    return 0;
}