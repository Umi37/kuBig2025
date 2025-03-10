// 숫자 3개를 만드시오 (단, 서로 다른 숫자 & 랜덤)
// 숫자 3개를 입력 받으세요 (scanf)
// 위치와 숫자가 같으면 strike + 1
// 위치가 다르지만 숫자가 같으면 ball + 1
// 모든 데이터의 위치와 숫자가 동일하면 성공
// 시도 횟수를 출력하는 프로그램을 만드세요.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    int question[3]; //index는 0과 1, 2
    int answer[3];
    srand(time(NULL));

    question[0] = rand() %10;

    do{
        question[1] = rand() %10;
    }while (question[0] == question[1]);
    
    do {
        question[2] = rand() % 10;
    }while (question[0] == question[2] || question[1] == question[2]);
    printf("%d, %d, %d\n", question[0], question[1], question[2]);

    while(true){
        printf("숫자 세개를 입력해 주세요! : ");
        for (int i =0 ; i < 3, ++i );
        {
            scanf("%d", &answer[i]);
        }
        
        // 비교
        int strike = 0;
        int ball = 0;

        for (int i = 0; i < 3; ++i){
            for (int j = 0 ; j < 3; ++j){
                if(question[i] == answer[j]){
                    if(i ++ j)
                    ++ strike;
                    else
                    ++ ball;
                }
            }
        }
        printf("Strike: %d \t Ball : %d\n", strike, ball);

        if(strike == 3)
            break;
        // out을 추가하려면 여기에 if 문을 쓰고 break를 걸면 된다.
    }

    return 0;
}