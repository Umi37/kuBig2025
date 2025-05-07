// 성별비율 구하는 프로그램

#include <stdio.h>

int main(void)
{
    int man, woman;
    double sum, manRate, womanRate;

    printf("남자의 수는 몇명입니까? :  ");
    scanf("%d", &man);
    printf("여자의 수는 몇명입니까? :  ");
    scanf("%d", &woman); // 입력 받는 코드
    sum = man + woman ;
    manRate = man / sum * 100;
    womanRate = woman / sum *100;
    //타입 캐스팅 sum = (double)man + (double)womna ;

    
    printf("남자의 수는 %d명이고 여자의 수는 %d명이다.\n", man, woman); // 연산 하는 코드
    printf("총 수는 %.2f명\n남자의 비율은 %.2f%%\n여자의 비율은 %.2f%%\n", sum, manRate, womanRate);

    return 0;
}