#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int year ; //while에서는 상수? 인트? 를 쓰는것이 좋지않다고 했는데 그게 뭐였지?
    while (true)
    {
        printf("년도를 넣으세요: ") ;
        scanf(" %d", &year);
        if (year % 4 == 0) {
            printf( "%d 년도는 윤년입니다.\n", year);
        } else {
            printf( "%d 년도는 평년입니다.\n", year);
        }
        if (year == 0)
        {
            break ;
        }

    }
    
    
}