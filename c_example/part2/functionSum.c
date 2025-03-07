// 매개변수 두개를 int 로 받아서 더해서 리턴하는 함수

#include <stdio.h>

int sum(int a, int b); // 받을 매개변수의 이름 이렇게 써도되고 int sum(int , int ); 이렇게 안써도됨
                       // 여기서의 a, b 는 전역 변수
int main(void)
{
    int a = 10, b = 20 ; // 여기서의 a, b 는 지역 변수
    int result ;

    result = sum(a,b);
    printf("%d + %d = %d 입니다.: " , a, b, result);
    return 0; 
}

int sum(int a, int b) // 함수의 정의는 선언된 그대로 해줘야함 
                      // 여기서의 a, b 는 전역변수
{
    int temp ; 
    temp = a + b;
    return temp ;

}
