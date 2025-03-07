// 10개 짜리 배열을 랜덤으로 0 ~100 만들어서 인트를 하나 sacnf 으로 받는다.
// 같은 원소가 있는지 index 가 몇 번째 인지 프린트 하시오.

#include <stdlib.h>
#include <time.h>

int main(void)
{
    int randomNumber[10];
    int value;

    srand((unsigned int)time(NULL));
    for (int i = 0 ; i <10; ++i)
    {
        randomNumber[i] = rand() % 101;
        printf("%d ,  ", randomNumber[i]);
    }
    printf("\n");
    int i;
    for (i = 0; i < 10; ++i)
    {
        if (value == randomNumber[i])
            break;
    }
    if (i < 10)
    {
        printf("%d 숫자를 찾았다. 인덱스는 %d 이다. \n", value, i);
    }
    else
    {
        printf("%d숫자를 못 찾았다. \n", value);
    }
    return 0 ;
}







srand((unsigned))
for (int i = 0; i < 10; ++i)
{
    randomNumber[i]
}




printf("\n");
int i ;
for ( i = 0 ; i < 10)



