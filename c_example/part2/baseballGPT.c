// #include <stdio.h>
// #include <unistd.h>  // usleep() 사용 (마이크로초 단위)

// void animateBaseball();

// int main(void) {
//     printf("-----------------------------------\n");
//     printf("      🔥 Baseball Game Start 🔥\n");
//     printf("-----------------------------------\n");
//     fflush(stdout);
//     sleep(2);

//     printf("   진행하시려면 엔터를 누르세요\n");
//     printf("-----------------------------------\n");
//     getchar();

//     // 야구 애니메이션 실행
//     animateBaseball();

//     return 0;
// }

// void animateBaseball() {
//     char *frames[] = {
//         "🏏          ⚾",
//         "  🏏        ⚾",
//         "    🏏      ⚾",
//         "      🏏    ⚾",
//         "        🏏  ⚾",
//         "          🏏⚾",  
//         "            💥 (HIT!)"
//     };

//     for (int i = 0; i < 7; i++) {
//         printf("\r%s", frames[i]);  // 기존 줄을 덮어씌움
//         fflush(stdout);
//         usleep(30000);  // 0.3초 대기
//     }

//     printf("\n-----------------------------------\n");
//     printf("🏆 홈런!! 게임 시작!!\n");
//     printf("-----------------------------------\n");
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // 여러 줄 애니메이션 프레임
    char *frames[] = {
        "   ⚾  \n"
        "       \n"
        "       \n",

        "      \n"
        "   ⚾  \n"
        "      \n",

        "       \n"
        "       \n"
        "   ⚾  \n"
    };

    int numFrames = sizeof(frames) / sizeof(frames[0]); // 프레임 개수

    for (int i = 0; i < 10; i++) { // 애니메이션 반복 실행
        system("clear");  // 화면 지우기 (Mac, 리눅스) / Windows에서는 "cls"
        printf("%s", frames[i % numFrames]); // 프레임 출력
        fflush(stdout);
        usleep(300000); // 0.3초 대기
    }

    return 0;
}
