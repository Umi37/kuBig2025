// 1~127 아스키 코드를 출력하세요. - char ch = 0
// ==> printf("%c", ch);
// 이중 for문으로 만드세요.
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
// 8 줄 출력

#include <stdio.h>

int main(void)
{
    char ch; //변수 선언
    for (int j = 0; j <= 7; ++j)
    {   
        printf("\n");
        for (int i = 0; i <= 15; ++i)
        {
            ch = i + 16 * j;
            printf("%d : %c   ", ch, ch);
        }
    }
    return 0 ;
}