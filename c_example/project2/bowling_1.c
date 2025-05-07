#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include </opt/homebrew/Cellar/mysql-client/9.2.0/include/mysql/mysql.h>
            // MySQL을 C에서 사용하기 위한 헤더 파일인데 인식되지 않아서 경로로 추가함

// MySQL 연결 정보
#define SERVER "localhost"
#define USER "root"
#define PASSWORD "0000"
#define DATABASE "bowling_db"

// 게임에서 사용할 구조체
typedef struct {
    char player1[50]; // 첫번째 플레이어의 이름
    char player2[50]; // 두번째 플레이어의 이름
    int frame; // 현재 프레임 번호
    int first; // 첫 번째 투구 점수
    int second; // 두 번째 투구 점수
    int total; // 해당 프레임의 총 점수
    int is_strike; // 스트라이크 여부 ( 1 = O , 0 = X )
    int is_spare; // 스페어 여부 ( 1 = O , 0 = X )
    char play_date[11];
} bowling_game ;

typedef struct {
    char name[50];        // 플레이어 이름
    char phone[15];       // 전화번호
    int score;            // 총 점수
    char play_date[11];   // 플레이 날짜 (YYYY-MM-DD)
} game_data;

enum main_menu
{
    play,
    data,
    exit_menu
};

void print_menu(void)
{
    system("clear");
    printf("🟡⚪️🔵🟡⚪️🔵 WELCOM TO THE BOWLING FACTORY 🟡⚪️🔵🟡⚪️🔵\n");
    printf("-------------------------------------------------------\n");
    printf("🎳 0. PLAY GAME\n");
    printf("🎳 1. MEMBERSHIP MANAGEMENT\n");
    printf("🎳 2. EXIT MENU\n");
    printf("-------------------------------------------------------\n");
}

int is_valid_date(const char *date) {
    int year, month, day;
    if (sscanf(date, "%4d-%2d-%2d", &year, &month, &day) == 3) {
        if (month >= 1 && month <= 12 && day >= 1 && day <= 31) {  
            return 1; 
        }
    }
    return 0;
}

void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';  // 개행 문자를 문자열 종료 문자('\0')로 변경
    }
}

#define MAX_FRAMES 10
#define BONUS_FRAMES 2  // 10프레임에서 보너스 투구 가능

void start_game() {
    bowling_game game[MAX_FRAMES + BONUS_FRAMES];  // 보너스 투구 공간 확보
    int total_score_p1 = 0;

    // 배열 초기화 (쓰레기 값 방지)
    memset(game, 0, sizeof(game));

    while (1) {
        printf("\n🎳 게임을 시작합니다! 🎳\n");
        printf("게임 날짜를 입력하세요 (YYYY-MM-DD): ");
        scanf("%10s", game[0].play_date);

        if (is_valid_date(game[0].play_date)) {
            break;
        } else {
            printf("⚠️ 잘못된 날짜 형식입니다. 다시 입력하세요!\n");
        }
    }

    getchar();  

    // 플레이어 1 이름 입력
    printf("플레이어 1의 이름을 입력하세요: ");
    fgets(game[0].player1, sizeof(game[0].player1), stdin);
    remove_newline(game[0].player1);

    printf("플레이어 2의 이름을 입력하세요: ");
    fgets(game[0].player2, sizeof(game[0].player2), stdin);
    remove_newline(game[0].player2);

    printf("-------------------------------------------------------\n");
    printf("\n✅ 입력된 날짜: %s\n", game[0].play_date);
    printf("🎳 플레이어 1: %s\n", game[0].player1);
    printf("🎳 플레이어 2: %s\n", game[0].player2);

    printf("-------------------------------------------------------\n");
    
    printf("================= 🎳 게임을 시작합니다 🔥 ================== \n");

    // 🎯 10프레임 진행
    for (int i = 0; i < MAX_FRAMES; i++) {
        game[i].frame = i + 1;
        printf("\n🎯 Frame %d\n", game[i].frame);

        // 🎳 첫 번째 투구
        printf("🎳 %s의 첫 번째 투구 점수: ", game[0].player1);
        scanf("%d", &game[i].first);

        if (game[i].first == 10) {  
            game[i].is_strike = 1;
            game[i].second = 0;
            printf("💥 스트라이크!\n");
        } else {
            // 🎳 두 번째 투구
            printf("🎳 %s의 두 번째 투구 점수: ", game[0].player1);
            scanf("%d", &game[i].second);
            if (game[i].first + game[i].second == 10) {  
                game[i].is_spare = 1;
                printf("✨ 스페어!\n");
            }
        }

        // 🎳 보너스 점수 계산 (다음 프레임이 존재하는 경우만)
        game[i].total = game[i].first + game[i].second;
        if (i < MAX_FRAMES - 1) {
            if (game[i].is_strike) {  // 스트라이크 보너스 (다음 2투구 합산)
                game[i].total += game[i+1].first + ((game[i+1].is_strike && i+2 < MAX_FRAMES) ? game[i+2].first : game[i+1].second);
            } else if (game[i].is_spare) {  // 스페어 보너스 (다음 1투구 합산)
                game[i].total += game[i+1].first;
            }
        }

        total_score_p1 += game[i].total;
        printf("\n🏆 현재 %s의 총 점수: %d\n", game[0].player1, total_score_p1);
    }

    // 🎳 10프레임 보너스 처리
    if (game[MAX_FRAMES - 1].is_strike) {  // 10프레임에서 스트라이크
        printf("🎳 %s의 보너스 첫 번째 투구 점수: ", game[0].player1);
        scanf("%d", &game[MAX_FRAMES].first);
        printf("🎳 %s의 보너스 두 번째 투구 점수: ", game[0].player1);
        scanf("%d", &game[MAX_FRAMES + 1].first);
        total_score_p1 += game[MAX_FRAMES].first + game[MAX_FRAMES + 1].first;
    } else if (game[MAX_FRAMES - 1].is_spare) {  // 10프레임에서 스페어
        printf("🎳 %s의 보너스 투구 점수: ", game[0].player1);
        scanf("%d", &game[MAX_FRAMES].first);
        total_score_p1 += game[MAX_FRAMES].first;
    }

    // 🎳 최종 점수 출력
    printf("\n================= 🎳 게임 종료! ==================\n");
    printf("🏆 최종 점수: %d\n", total_score_p1);
}

void calculate_score(bowling_game game[]) {
    int total_score = 0;

    for (int i = 0; i < 10; i++) {
        game[i].total = game[i].first + game[i].second;
        total_score += game[i].total;
    }

    printf("최종 점수: %d\n", total_score);
}


// 회원 관리 함수 (임시)
void manage_members() {
    printf("\n📋 회원 관리 시스템에 진입했습니다.\n");
    // 이후 MySQL 연동 코드 추가 예정
}


void save_score_to_db(char *name, char *phone, int score)
{
    printf("\n📋 게임 결과를 저장합니다.\n");
}


// 메인 함수
int main() {
    int choice;  // 사용자의 선택을 저장할 변수

    while (1) {  // 무한 반복 (exit_menu 선택 시 종료)
        print_menu();  // 메뉴 출력
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        // 메뉴 선택 처리
        switch (choice) {
            case play:
                start_game();  // 게임 시작 함수 호출
                break;
            case data:
                manage_members();  // 회원 관리 함수 호출
                break;
            case exit_menu:
                printf("\n프로그램을 종료합니다. 🎳\n");
                return 0;  // 프로그램 종료
            default:
                printf("\n⚠️ 잘못된 입력입니다. 다시 선택하세요!\n");
        }

        printf("\n아무 키나 누르면 메뉴로 돌아갑니다...\n");
        getchar();  // 이전 입력을 제거
        getchar();  // 사용자의 입력 대기
    }

    // MySQL 연결 정보
    #define server "localhost"
    #define user "root"
    #define password "0000"
    #define database "bowling_db"
    
    MYSQL *conn;    // MYSQL : 데이터베이스 연결을 나타내는 구조체
                    // *conn : MYSQL 타입의 포인터 변수 `conn` 선언 (MySQL과의 연결을 관리하는 객체)
                    // conn 이라는 변수를 선언해서 MySQL 서버와의 연결을 설정하고, SQL 명령을 실행할 수 있도록 함



    // MySQL 초기화
    conn = mysql_init(NULL);
    if (conn == NULL) {
        printf("MySQL 초기화 실패\n");
        return 1;
    }

    // MySQL 연결
    if (mysql_real_connect(conn, server, user, password, database, 0, NULL, 0) == NULL) {
        printf("MySQL 연결 실패: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    printf("MySQL 연결 성공!\n");

    // 연결 종료
    mysql_close(conn);
    return 0;
}