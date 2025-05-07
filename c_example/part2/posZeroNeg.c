// 숫자를 입력 받아서 양수, 제로, 음수를 출력하는 프로그램
// if else 구문으로 만드세요.
// printf 는 한 번 만 쓰세요.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int num;
    if (argc < 2)
    {
    num = atoi(argv[1]);
    }
    
    printf("%s 는 %s", argv[1], atoi(argv[1]) >= 0 ? "양수 입니다!" : "음수 입니다!") ;
        
    return 0 ;
    
}