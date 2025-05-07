#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int year ; //변수는 메모리에 공간을 확보하게 되는데, while 속에 있으면 해제되고 할당되고 반복되니까, 비효율
    while (true)
    {
        printf("년도를 넣으세요: ") ;
        scanf(" %d", &year);
        // if (year % 4 == 0) {
        //     printf( "%d 년도는 윤년입니다.\n", year);
        // } else {
        //     printf( "%d 년도는 평년입니다.\n", year);
        // }
        printf("%d 년도는 %s 입니다.\n", year, year %4 ? "평년" : "윤년");

        if (!year)
               break ;
    }

}
    
    
