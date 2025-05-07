#include <stdio.h> // 표준 입출력 라이브러리 포함
#include <stdlib.h>
#include <string.h>
#include </opt/homebrew/Cellar/mysql-client/9.2.0/include/mysql/mysql.h>
            // MySQL을 C에서 사용하기 위한 헤더 파일인데 인식되지 않아서 경로로 추가함

// MySQL 연결 정보
#define SERVER "localhost"
#define USER "root"
#define PASSWORD "0000"
#define DATABASE "bowling_db"

// 총 프레임 수 정의
#define FRAMES 10

typedef struct {
    char name1[50]; // 첫번째 플레이어의 이름
    char name2[50]; // 두번째 플레이어의 이름
    char phone_number1[15]; 
    char phone_number2[15];
    char play_date[11];
} bowling_game ;

// 각 플레이어의 점수를 저장하는 구조체
typedef struct {
    char name[50];
    int rolls[21]; // 최대 21번 투구 가능 (스트라이크 포함)
    int currentRoll; // 현재 투구 횟수 저장
    int totalScore; // 총 점수 저장
} Player;

enum main_menu
{
    PLAY_GAME,
    MEMBERSHIP_MANAGEMENT,
    EXIT_MENU
};

MYSQL *connect_db();
void manageMembership();
void registerMember();
void deleteMember();
void viewMembers();
void print_menu();
void updateMonthlyStats(char *name, char *phone, char *play_date);


// ✅ MySQL 연결 함수
MYSQL *connect_db()
{
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL)
    {
        fprintf(stderr, "MySQL 초기화 실패: %s\n", mysql_error(conn));
        exit(1);
    }

    if (mysql_real_connect(conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL)
    {
        fprintf(stderr, "MySQL 연결 실패: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    return conn;
}

// ✅ 회원 등록 기능 (score 테이블에 점수 없이 추가)
void registerMember()
{
    MYSQL *conn = connect_db();
    char query[256];
    char name[50], phone[15];

    printf("👤 회원 이름 입력: ");
    scanf("%s", name);
    printf("📞 전화번호 입력 (예: 01012345678): ");
    scanf("%s", phone);

    snprintf(query, sizeof(query),
             "INSERT INTO score (name, phone_number, score, play_date) VALUES ('%s', '%s', NULL, NULL)",
             name, phone);

    if (mysql_query(conn, query))
    {
        fprintf(stderr, "⚠️ MySQL 오류: %s\n", mysql_error(conn));
    }
    else
    {
        printf("✅ 회원이 등록되었습니다!\n");
    }

    mysql_close(conn);
}

// ✅ 회원 삭제 기능
void deleteMember()
{
    MYSQL *conn = connect_db();
    char query[256];
    char phone[15];

    printf("🗑 삭제할 회원의 전화번호 입력: ");
    scanf("%s", phone);

    snprintf(query, sizeof(query),
             "DELETE FROM score WHERE phone_number='%s'", phone);

    if (mysql_query(conn, query))
    {
        fprintf(stderr, "⚠️ MySQL 오류: %s\n", mysql_error(conn));
    }
    else
    {
        printf("✅ 회원이 삭제되었습니다! (연관 데이터도 삭제됨)\n");
    }

    mysql_close(conn);
}

// ✅ 회원 목록 조회 기능
void viewMembers()
{
    MYSQL *conn = connect_db();
    MYSQL_RES *result;
    MYSQL_ROW row;
    char query[128] = "SELECT name, phone_number FROM score";

    if (mysql_query(conn, query))
    {
        fprintf(stderr, "⚠️ MySQL 오류: %s\n", mysql_error(conn));
        mysql_close(conn);
        return;
    }

    result = mysql_store_result(conn);
    if (result == NULL)
    {
        fprintf(stderr, "⚠️ MySQL 결과 오류: %s\n", mysql_error(conn));
        mysql_close(conn);
        return;
    }

    printf("\n📋 회원 목록\n");
    printf("----------------------------\n");
    printf("| 이름       | 전화번호    |\n");
    printf("----------------------------\n");

    while ((row = mysql_fetch_row(result)))
    {
        printf("| %-10s | %-11s |\n", row[0], row[1]);
    }

    printf("----------------------------\n");

    mysql_free_result(result);
    mysql_close(conn);
}

// ✅ 회원 관리 메뉴
void manageMembership()
{
    int choice;

    while (1)
    {
        printf("\n🔹 회원 관리 메뉴\n");
        printf("1️⃣ 회원 등록\n");
        printf("2️⃣ 회원 삭제\n");
        printf("3️⃣ 회원 목록 조회\n");
        printf("4️⃣ 뒤로 가기\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            registerMember();
            break;
        case 2:
            deleteMember();
            break;
        case 3:
            viewMembers();
            break;
        case 4:
            return;
        default:
            printf("⚠️ 올바른 선택이 아닙니다!\n");
        }
    }
}

// ✅ 월별 통계 업데이트
void updateMonthlyStats(char *name, char *phone, char *play_date)
{
    MYSQL *conn = connect_db();
    char query[512];
    char month_year[8];

    strncpy(month_year, play_date, 7);
    month_year[7] = '\0';

    snprintf(query, sizeof(query),
             "INSERT INTO monthly_stats (name, phone_number, month_year, games_played) "
             "VALUES ('%s', '%s', '%s', 1) "
             "ON DUPLICATE KEY UPDATE games_played = games_played + 1",
             name, phone, month_year);

    if (mysql_query(conn, query))
    {
        fprintf(stderr, "⚠️ MySQL 오류: %s\n", mysql_error(conn));
    }

    mysql_close(conn);
}


const char *scoreCheck(int score, int nextRoll, int isFirstRoll) {
    if (score == 10 && isFirstRoll) return "X";  // 스트라이크
    if (score + nextRoll == 10 && !isFirstRoll) return "/"; // 스페어
    if (score == 0) return "-"; // 미스

    static char buffer[3];
    snprintf(buffer, sizeof(buffer), "%d", score);
    return buffer;
}


void print_menu(void);
void init_Player(Player *player);
void roll(Player *player, int pins);
int calculateScore(Player *player);
void displayScores(Player *player1, Player *player2, int frame);
void playGame(Player *player1, Player *player2);
int is_valid_date(const char *date);
void remove_newline(char *str);
void updateMonthlyStats(char *name, char *phone, char *play_date);


void print_menu(void) {
    int choice;
    
    while (1) {  // 무한 루프 -> 사용자가 EXIT_MENU 선택할 때까지 반복
        system("clear");  // 화면 정리
        printf("🟡⚪️🔵🟡⚪️🔵 WELCOME TO THE BOWLING FACTORY 🟡⚪️🔵🟡⚪️🔵\n");
        printf("-------------------------------------------------------\n");
        printf("🎳 0. PLAY GAME\n");
        printf("🎳 1. MEMBERSHIP MANAGEMENT\n");
        printf("🎳 2. EXIT MENU\n");
        printf("-------------------------------------------------------\n");
        printf("메뉴를 선택하세요: ");
        
        if (scanf("%d", &choice) != 1) {  // 숫자가 아닌 값이 입력되었을 경우 방지
            printf("⚠️ 잘못된 입력입니다! 숫자를 입력하세요.\n");
            while (getchar() != '\n');  // 입력 버퍼 비우기
            continue;
        }

        // 🔥 메뉴 선택 처리
        switch (choice) {
            case PLAY_GAME:
                system("clear"); 
                printf("\n🎳 게임을 시작합니다!\n");
                Player player1, player2;
                init_Player(&player1);
                init_Player(&player2);
                playGame(&player1, &player2);
                break;

                case MEMBERSHIP_MANAGEMENT:
                system("clear");
                printf("\n👥 회원 관리 시스템을 실행합니다!\n");
                manageMembership();  // 🔥 회원 관리 기능 실행
                break;

            case EXIT_MENU:
                printf("\n🚪 프로그램을 종료합니다.\n");
                return;  // 함수 종료 (메뉴 루프 종료)

            default:
                printf("⚠️ 잘못된 메뉴 번호입니다. 다시 선택하세요!\n");
        }

        printf("\n아무 키나 누르면 메뉴로 돌아갑니다...\n");
        getchar();  // 엔터 키 입력 대기
        getchar();  // 이전 입력 버퍼 처리
    }
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
    int score = 0;
    int rollIndex = 0;

    for (int frame = 0; frame < FRAMES; frame++) {
        if (player->rolls[rollIndex] == 10) { // 🎳 스트라이크
            score += 10 + player->rolls[rollIndex + 1] + player->rolls[rollIndex + 2];
            rollIndex += 1;
        } 
        else if (player->rolls[rollIndex] + player->rolls[rollIndex + 1] == 10) { // 🎳 스페어
            score += 10 + player->rolls[rollIndex + 2];
            rollIndex += 2;
        } 
        else { // 🎳 일반 프레임
            score += player->rolls[rollIndex] + player->rolls[rollIndex + 1];
            rollIndex += 2;
        }
    }

    // ✅ **10프레임에서 추가 점수를 또 더하는 실수를 방지**
    return score;
}



void displayScores(Player *player1, Player *player2, int currentFrame) {
    system("clear"); // ✅ 이전 점수판을 지우고 새로운 스코어보드를 출력

    printf("\n🎳 Bowling Scoreboard 🎳\n");
    printf("-----------------------------------------------------------------------------------------------\n");

    // 프레임 번호 출력
    printf("| Frame       |");
    for (int i = 0; i < FRAMES; i++) {
        printf("  %4d  |", i + 1);
    }
    printf("\n-----------------------------------------------------------------------------------------------\n");

    // 플레이어 1 점수 출력
    printf("| %-10s |", player1->name);
    int rollIndex1 = 0;
    for (int i = 0; i < FRAMES; i++) {
        if (i <= currentFrame) { // 진행된 프레임까지만 점수 표시
            printf(" %4s ", scoreCheck(player1->rolls[rollIndex1], player1->rolls[rollIndex1 + 1], 1));
            if (player1->rolls[rollIndex1] < 10 || i == FRAMES - 1) {
                printf("%4s |", scoreCheck(player1->rolls[rollIndex1 + 1], player1->rolls[rollIndex1 + 2], 0));
                rollIndex1 += 2;
            } else {
                printf("   |"); // 스트라이크는 첫 투구만 표시
                rollIndex1 += 1;
            }
        } else {
            printf("     |"); // 아직 진행되지 않은 프레임은 빈칸
        }
    }
    printf("\n-----------------------------------------------------------------------------------------------\n");

    // 플레이어 1 총 점수 출력
    printf("| Total Score |");
    rollIndex1 = 0;
    int totalScore1 = 0;
    for (int i = 0; i < FRAMES; i++) {
        if (i <= currentFrame) {
            totalScore1 = calculateScore(player1);
            printf("  %4d  |", totalScore1);
        } else {
            printf("     |");
        }
    }
    printf("\n-----------------------------------------------------------------------------------------------\n");

    // 플레이어 2 점수 출력
    printf("| %-10s |", player2->name);
    int rollIndex2 = 0;
    for (int i = 0; i < FRAMES; i++) {
        if (i <= currentFrame) {
            printf(" %4s ", scoreCheck(player2->rolls[rollIndex2], player2->rolls[rollIndex2 + 1], 1));
            if (player2->rolls[rollIndex2] < 10 || i == FRAMES - 1) {
                printf("%4s |", scoreCheck(player2->rolls[rollIndex2 + 1], player2->rolls[rollIndex2 + 2], 0));
                rollIndex2 += 2;
            } else {
                printf("   |");
                rollIndex2 += 1;
            }
        } else {
            printf("     |");
        }
    }
    printf("\n-----------------------------------------------------------------------------------------------\n");

    // 플레이어 2 총 점수 출력
    printf("| Total Score |");
    rollIndex2 = 0;
    int totalScore2 = 0;
    for (int i = 0; i < FRAMES; i++) {
        if (i <= currentFrame) {
            totalScore2 = calculateScore(player2);
            printf("  %4d  |", totalScore2);
        } else {
            printf("     |");
        }
    }
    printf("\n-----------------------------------------------------------------------------------------------\n");
}



// 게임을 진행하는 함수
void playGame(Player *player1, Player *player2) {

    bowling_game game;
    while (1) {
        system("clear"); 
        printf("\n🎳 게임을 시작합니다! 🎳\n");
        printf("게임 날짜를 입력하세요 (YYYY-MM-DD): ");
        scanf("%10s", game.play_date);

        if (is_valid_date(game.play_date)) {
            break;
        } else {
            printf("⚠️ 잘못된 날짜 형식입니다. 다시 입력하세요!\n");
        }
    }

    getchar();  

    // 플레이어 1 이름 입력
    system("clear"); 
    // 플레이어 1 이름 입력
    printf("플레이어 1의 이름을 입력하세요: ");
    fgets(game.name1, sizeof(game.name1), stdin);
    remove_newline(game.name1);

    // 플레이어 1 전화번호 입력
    printf("플레이어 1의 전화번호를 입력하세요 (숫자만 입력, 예: 01012345678): ");
    scanf("%14s", game.phone_number1);
    getchar(); // 입력 버퍼 비우기

    printf("플레이어 2의 이름을 입력하세요: ");
    fgets(game.name2, sizeof(game.name2), stdin);
    remove_newline(game.name2);

    // 플레이어 2 전화번호 입력
    printf("플레이어 2의 전화번호를 입력하세요 (숫자만 입력, 예: 01012345678): ");
    scanf("%14s", game.phone_number2);
    getchar(); // 입력 버퍼 비우기

    system("clear"); 
    printf("-------------------------------------------------------\n");
    printf("\n✅ 입력된 날짜: %s\n", game.play_date);
    printf("🎳 플레이어 1: %s\n", game.name1);
    printf("🎳 플레이어 1: %s (📞 %s)\n", game.name1, game.phone_number1);
    printf("🎳 플레이어 2: %s\n", game.name2);
    printf("🎳 플레이어 2: %s (📞 %s)\n", game.name2, game.phone_number2);

    printf("진행을 계속 하시려면 아무 키나 누르세요.");
    getchar();  
    getchar();  

    // 🎯 `Player` 구조체에도 이름 복사
    strcpy(player1->name, game.name1);
    strcpy(player2->name, game.name2);

    printf("-------------------------------------------------------\n");



    system("clear"); 
    printf("================= 🎳 게임을 시작합니다./ 🔥 ================== \n");

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
        // ✅ 데이터베이스 저장 (게임 종료 후)
        player1->totalScore = calculateScore(player1);
        player2->totalScore = calculateScore(player2);

        updateMonthlyStats(player1->name, game.phone_number1, game.play_date);
        updateMonthlyStats(player2->name, game.phone_number2, game.play_date);


        printf("\n✅ 점수 및 기록이 데이터베이스에 저장되었습니다!\n");

    
}

// 프로그램의 시작점
int main() {

    print_menu(); 
    
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
