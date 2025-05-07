#include <stdio.h>

int main(void)
{
    int Korean = 70;
    int English = 80;
    int Mathmatic = 90;
    int sum = Korean + English + Mathmatic;

    printf("국어 : %d, ", Korean);
    printf("영어 : %d, ", English);
    printf("수학 : %d\n", Mathmatic);
    printf("총점 : %d\n", sum);

    printf("국어 데이터의 크기 : %ld바이트\n", sizeof(Korean));
    
    return 0;
}