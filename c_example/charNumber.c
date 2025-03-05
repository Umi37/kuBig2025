// 문자(character)와 ASCII 코드 값 간의 변환 및 출력

#include <stdio.h> //printf, scanf 등의 함수를 담은 헤더 : C언어에서는 헤더를 포함해야 해당 함수를 사용할 수 있다.

int main() // main() 함수 : 프로그램의 시작점 (Entry Point)
           // C프로그램은 반드시 반드시 main() 함수가 있어야 실행 가능하다.
           // int 는 main() 함수가 정수를 반환(return)하는 함수임을 의미한다.
{
    char ch1 = 'A'; // char 자료형인 ch1라는 변수를 선언하고, 문자 'A'를 저장한다.
    char ch2 = 65 ; // char 자료형인 변수 ch2라는 변수를 선언하고, ASCII 코드 65에 해당하는 문자 ('A')를 저장한다.
    char ch3 ;      // char 자료형 변수 ch3를 선언 (초기화되지 않은 상태, 사용자 입력을 받을 예정)

    printf("ch1: %c Number : %d\n", ch1, ch1);
    // ch1을 %c(문자) 형식으로 출력하고, 같은 값을 %d(정수) 형식으로 출력하여 ASCII 코드 값을 확인한다.
    printf("ch2 %c Number : %d\n", ch2, ch2);
    // ch2도 동일하게 출력 
    printf("Input A character: ");
    scanf("%c", &ch3) ;
    printf("\nch3: %c Number: %d\n", ch3, ch3);

    return 0 ;
}