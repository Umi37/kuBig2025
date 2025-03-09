#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
    int threeNumbers[3];  // 컴퓨터가 생성한 난수
    int yourNumbers[3];   // 사용자가 입력한 숫자
    int strike, ball, attempts = 0;

    srand((unsigned int)time(NULL));

    // ✅ 1. 중복되지 않는 난수 생성
    for (int i = 0; i < 3; ++i)
    {
        int num;
        int duplication;
        do {
            duplication = 0;
            num = rand() % 10;  // 0~9 사이의 난수 생성

            for (int j = 0; j < i; ++j) {
                if (threeNumbers[j] == num) {
                    duplication = 1;  // 중복되면 다시 생성
                    break;
                }
            }
        } while (duplication);
        threeNumbers[i] = num;
    }

    // ✅ 2. 게임 시작 안내
    printf("-----------------------------------\n");
    printf("      🔥 Baseball Game Start! 🔥\n");
    printf("-----------------------------------\n");
    fflush(stdout);
    sleep(2);
    printf("   진행하시려면 엔터를 누르세요\n");
    printf("-----------------------------------\n");
    getchar();  // 사용자 엔터 입력 대기

    do {
        strike = 0;
        ball = 0;
        
        // ✅ 3. 사용자 입력 (중복되지 않은 숫자 입력받기)
        printf("-----------------------------------\n");
        printf("  0~9 사이의 숫자 3개를 입력하세요\n");
        printf("-----------------------------------\n");
        printf(": ");

        for (int i = 0; i < 3; ++i)
        {   
            int num;
            int duplication;
            do {
                duplication = 0;
                scanf("%d", &num);

                // 입력 버퍼 정리 (개행 문자 제거)
                while (getchar() != '\n');  

                for (int j = 0; j < i; ++j) {
                    if (yourNumbers[j] == num) {
                        printf("\n⚠ 중복되지 않은 숫자를 넣어주세요!\n\n");
                        duplication = 1;
                        break;   
                    }
                }
            } while (duplication);
            yourNumbers[i] = num;
        }

        // ✅ 4. Strike / Ball 판정
        for (int i = 0; i < 3; i++)
        {
            if (threeNumbers[i] == yourNumbers[i]) {
                strike++;  // 위치와 숫자 모두 일치 → Strike 증가
            }
            else {
                for (int j = 0; j < 3; j++)
                {
                    if (threeNumbers[i] == yourNumbers[j]) {
                        ball++;  // 숫자는 존재하지만 위치가 다름 → Ball 증가
                        break;
                    }
                }
            }
        }

        // ✅ 5. OUT 처리 (Strike & Ball이 모두 0일 때)
        if (strike == 0 && ball == 0) {
            printf("-----------------------------------\n");
            printf("   ❌❌❌❌❌❌ OUT ❌❌❌❌❌❌\n");
        }
        printf("-----------------------------------\n");

        // ✅ 6. 시도 횟수 증가 및 결과 출력
        attempts++;
        printf("-----------------------------------\n");
        printf("         %d 번째 시도입니다!\n", attempts);
        printf("-----------------------------------\n");
        printf("\n⚾ Strike : %d\n", strike); 
        printf("\n⚾ Ball : %d\n\n", ball);
        printf("-----------------------------------\n");

    } while (strike < 3);  // ✅ 7. 3 Strike가 될 때까지 반복

    // ✅ 8. 게임 종료 메시지
    printf("\n🎉 축하합니다! %d번의 시도 끝에 정답을 맞추셨습니다! 🎉\n", attempts);
    printf("✅ 정답: %d %d %d\n", threeNumbers[0], threeNumbers[1], threeNumbers[2]);
    printf("-----------------------------------\n");

    return 0;
}
