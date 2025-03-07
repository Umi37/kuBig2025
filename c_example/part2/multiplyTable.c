#include <stdio.h>

int main(void)
{
    for(int i = 2; i <= 9; ++i) // 단수 2단 ~ 9단 - i (for문 쓸 때 i를 많이 쓰는 이유- 역사적인 이유가 있다고함)
    {   
        printf("\n------%d단 입니다. ------\n\n", i);
        for(int j = 2; j <= 9 ; ++j) // 2 부터 9 까지 - j
        {
            printf("      %d X %d = %d\n", i, j, i * j);

        }
    }
    return 0 ;
}