#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int sum = 0 ;

    for(int i = 1; i <= 100 ; i++)
    {
        sum += i ;
    }

    printf("1부터 100까지의 합은 %d 입니다.\n", sum);

    return 0;
}
