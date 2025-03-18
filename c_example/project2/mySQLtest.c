#include <stdio.h>
#include </opt/homebrew/Cellar/mysql-client/9.2.0/include/mysql/mysql.h>
            // MySQL을 C에서 사용하기 위한 헤더 파일인데 인식되지 않아서 경로로 추가함

int main() {
    MYSQL *conn;    // MYSQL : 데이터베이스 연결을 나타내는 구조체
                    // *conn : MYSQL 타입의 포인터 변수 `conn` 선언 (MySQL과의 연결을 관리하는 객체)
                    // conn 이라는 변수를 선언해서 MySQL 서버와의 연결을 설정하고, SQL 명령을 실행할 수 있도록 함

    // MySQL 연결 정보
    char *server = "localhost"; // MySQL 서버 주소 (현재 PC에서 실행 중이므로 'localhost' 사용)
    char *user = "root";        // MySQL 접속 계정 (관리자 계정)
    char *password = "0000";    // MySQL 접속 비밀번호 (root 계정의 비밀번호)
    char *database = "bowling_db"; // 연결할 데이터베이스 이름

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
