// 문자열을 쓰는 두 가지 방법
#include <stdio.h>

int main(void)
{
    char *str1 = "hello";   // 변화를 줄 수 없다.
    char str2[] = "hello";  // 변화 가능 ( 지역 변수가 메모리 스택에 생김 )
    char str3[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char str4 = 'h';

    printf("%s\n", str1);
    printf("%s\n", str2); //0x7fffea5e57ec 로 출력되었는데, 7f 로 시작하면 스택영역임 (5f로 시작하면 코드영역)
    printf("%s\n", str3);
    printf("%c\n", str4);
    printf("-----------\n");
    printf("%p\n", &str1);
    printf("%p\n", &str2);
    printf("%p\n", &str3);
    printf("%p\n", &str4);
    printf("-----------");

    // str1[0] = 'H'; const 로 선언한 변수를 변경하려고 하면 컴파일 에러 발생
    str1[0] = 'H';
    printf("%s\n", str2);

    return 0;
}