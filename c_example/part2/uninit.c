#include <stdio.h>

int main(void)
{
    int uninitialized ;
    int initialized = 345 ; //초기화가 된거
    
    printf("초기화 되지 않은 변수: %d\n", uninitialized);
    printf("초기화 된 변수 : %d\n", initialized);

    return 0;
} 
