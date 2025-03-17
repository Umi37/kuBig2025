#include <stdio.h> // 표준 입출력 라이브러리 포함

#define FRAMES 10 // 총 프레임 수 정의

// 각 플레이어의 점수를 저장하는 구조체
typedef struct {
    int rolls[21]; // 최대 21번 투구 가능 (스트라이크 포함)
    int currentRoll; // 현재 투구 횟수 저장
    int totalScore; // 총 점수 저장
} Player;

// 플레이어 데이터 초기화 함수
void init_Player(Player *player) {
    for (int i = 0; i < 21; i++) {
        player->rolls[i] = 0; // 모든 투구 점수를 0으로 초기화
    }
    player->currentRoll = 0; // 현재 투구 위치 초기화
    player->totalScore = 0; // 총 점수 초기화
}

// 투구 점수 기록 함수
void roll(Player *player, int pins) {
    player->rolls[player->currentRoll++] = pins; // 현재 투구 위치에 점수 저장 후 다음 위치로 이동
}

// 점수를 계산하는 함수
int calculateScore(Player *player) {
    int score = 0; // 총 점수 변수
    int rollIndex = 0; // 투구 배열의 현재 인덱스
    for (int frame = 0; frame < FRAMES; frame++) {
        if (player->rolls[rollIndex] == 10) { // 스트라이크일 경우
            score += 10 + player->rolls[rollIndex + 1] + player->rolls[rollIndex + 2]; // 다음 두 번의 투구 점수를 추가
            rollIndex += 1; // 스트라이크는 한 번만 투구하므로 인덱스를 1 증가
        } else if (player->rolls[rollIndex] + player->rolls[rollIndex + 1] == 10) { // 스페어일 경우
            score += 10 + player->rolls[rollIndex + 2]; // 다음 한 번의 투구 점수를 추가
            rollIndex += 2; // 스페어는 두 번 투구했으므로 인덱스를 2 증가
        } else { // 일반 점수 계산
            score += player->rolls[rollIndex] + player->rolls[rollIndex + 1]; // 현재 프레임 점수 추가
            rollIndex += 2; // 두 번의 투구를 했으므로 인덱스를 2 증가
        }
    }
    return score; // 최종 점수 반환
}

// 현재까지의 점수를 화면에 출력하는 함수
void displayScores(Player *player1, Player *player2, int frame) {
    printf("\n[%d번째 프레임 결과]\n", frame + 1);
    printf("플레이어 1 점수: %d\n", calculateScore(player1));
    printf("플레이어 2 점수: %d\n\n", calculateScore(player2));
}

// 게임을 진행하는 함수
void playGame(Player *player1, Player *player2) {
    for (int frame = 0; frame < FRAMES; frame++) { // 10프레임 동안 반복
        int firstRoll, secondRoll = 0;
        printf("플레이어 1 - %d번째 프레임 첫 번째 투구 점수 입력: ", frame + 1);
        scanf("%d", &firstRoll);
        roll(player1, firstRoll);

        if (firstRoll < 10 || frame == FRAMES - 1) { // 스트라이크가 아닐 경우 또는 마지막 프레임
            printf("플레이어 1 - %d번째 프레임 두 번째 투구 점수 입력: ", frame + 1);
            scanf("%d", &secondRoll);
            roll(player1, secondRoll);
        }

        if (frame == FRAMES - 1 && (firstRoll == 10 || firstRoll + secondRoll == 10)) { // 10프레임에서 스트라이크 또는 스페어일 경우
            int thirdRoll;
            printf("플레이어 1 - 10번째 프레임 추가 투구 점수 입력: ");
            scanf("%d", &thirdRoll);
            roll(player1, thirdRoll);
        }

        firstRoll = secondRoll = 0; // 변수 초기화
        printf("플레이어 2 - %d번째 프레임 첫 번째 투구 점수 입력: ", frame + 1);
        scanf("%d", &firstRoll);
        roll(player2, firstRoll);

        if (firstRoll < 10 || frame == FRAMES - 1) { // 스트라이크가 아닐 경우 또는 마지막 프레임
            printf("플레이어 2 - %d번째 프레임 두 번째 투구 점수 입력: ", frame + 1);
            scanf("%d", &secondRoll);
            roll(player2, secondRoll);
        }

        if (frame == FRAMES - 1 && (firstRoll == 10 || firstRoll + secondRoll == 10)) { // 10프레임에서 스트라이크 또는 스페어일 경우
            int thirdRoll;
            printf("플레이어 2 - 10번째 프레임 추가 투구 점수 입력: ");
            scanf("%d", &thirdRoll);
            roll(player2, thirdRoll);
        }

        displayScores(player1, player2, frame); // 현재까지의 점수 출력
    }
}

// 프로그램의 시작점
int main() {
    Player player1, player2; // 두 명의 플레이어 선언
    init_Player(&player1); // 플레이어 1 초기화
    init_Player(&player2); // 플레이어 2 초기화

    playGame(&player1, &player2); // 볼링 게임 시작

    printf("\n게임 종료! 최종 점수:\n");
    printf("플레이어 1: %d점\n", player1.totalScore = calculateScore(&player1));
    printf("플레이어 2: %d점\n", player2.totalScore = calculateScore(&player2));

    if (player1.totalScore > player2.totalScore) { // 승자 판별
        printf("플레이어 1이 승리했습니다!\n");
    } else if (player1.totalScore < player2.totalScore) {
        printf("플레이어 2가 승리했습니다!\n");
    } else {
        printf("무승부입니다!\n");
    }

    return 0; // 프로그램 종료
}
