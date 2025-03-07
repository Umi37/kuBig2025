// // 별표를 5줄 하나씩 늘어나는 모양을 출력하세요.
// // *
// // **
// // ***
// // ****
// // *****
// // 별표를 5줄 피라미드 모양으로 출력하세요

// //     **
// //    ****
// //   ******
// //  ********
// // **********

// // #include <stdio.h>   //for(int i = 2; i <= 9; ++i) /

// // int main(void)
// // {
     
// //     for(int i = 1; i <= 5; ++i)
// //     {
// //         for(int j = i ; j <= i; ++j)
// //         {
// //         printf("*\n");
// //         }
        
// //     }
// //     return 0;
// // }

// #include <stdio.h>

// int main(void)
// {
//     for(int i = 1; i <= 5; ++i)
//     {
//         for(int j = 1; j <= i; ++j)  // j가 1부터 i까지 증가하면서 별 출력
//         {
//             printf("*");
//         }
//         printf("\n");  // 줄 바꿈
//     }

//     return 0;  // 이제 모든 반복이 끝난 후 종료
// }

#include <stdio.h>

int main() {
    for (int i = 1; i <= 5; i++) {  // 줄 개수 (5줄 출력)
        for (int j = 1; j <= i; j++) {  // i번 만큼 별 출력
            printf("*");
        }
        printf("\n");  // 줄 바꿈
    }
    return 0;
}

