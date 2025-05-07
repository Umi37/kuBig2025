// 1~10 까지 do while 로 출력하기
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int i = 1 ;
    do
    {     
        printf("%d 번 출력입니다.\n", i ) ;
        ++i;
    } while ( i < 11) ;
    return 0 ;

}

//do while 은 이건 꼭 실행해놓고 조건문을 실행해야겠다 쓸 때 빼놓고는 잘 안쓰긴 함