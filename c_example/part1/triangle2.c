#include <stdio.h>

int main(void)
{

    // double 로 작성해 주세요. int 정수로 작성하면 소수점은 버림되니까 계산값이 오류생김

    double length ;
    double height ;
    double area ;

    printf("Enter triangle's length : ");
    scanf("%lf", &length);
    printf("Enter triangle's height : ");
    scanf("%lf", &height);
    area = length * height / 2.0 ; // 2가 아니라 2.0 
    printf("triangle's area is  : %.2f\n", area) ; //%f 를 %.2f 로 하면 소숫점 둘째 자리까지 출력

    return 0 ;
}