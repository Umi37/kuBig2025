#include <stdio.h>

int main(void) {
    int arr1[3] = {8, 1, 3};  // 첫 번째 배열
    int arr2[3] = {1, 9, 3};  // 두 번째 배열
    int strike = 0;
    int ball = 0;
    int out;  // 일치하는 요소 개수를 셈

    // 배열의 각 요소들을 비교하기 위한 이중 for문
    for (int i = 0; i < 3; i++) {
        if (arr1[i] == arr2[i]) {
            strike++ ;
        }
        else {
            for ( int j = 0; j < 3 ; j++) {
                if (arr1[i] == arr2[j] && i != j) {
                    ball++ ;
                }
            }
        }
        
        }


        printf("Strike : %d\n" , strike);
        printf("Ball : %d\n", ball);

        return 0 ;

    }

