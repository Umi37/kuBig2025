// 숫자 3개를 만드시오 (단, 서로 다른 숫자 & 랜덤)
// 숫자 3개를 입력 받으세요 (scanf)
// 위치와 숫자가 같으면 strike + 1
// 위치가 다르지만 숫자가 같으면 ball + 1
// 모든 데이터의 위치와 숫자가 동일하면 성공
// 시도 횟수를 출력하는 프로그램을 만드세요.
// 숫자 범위는 0~9

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int threeNumbers [3];
    int yourNumbers [3];

    srand((unsigned int)time(NULL));
    for (int i = 0; i < 3; ++i)
    {
        threeNumbers [i] = rand() % 10 ;
        // printf("%d ", randomNumber[i]);
    }
    printf("0~9 사이의 숫자 3개를 입력하세요 : ");

    for (int i =0; i <3; ++i)
    {
        scanf("%d", &yourNumbers[i]);
    }
   
    return 0;

}
