// 100 + 101 + .... + 10000
// 10100 * (10000 - 100) / 2

#include <stdio.h>

int main(void)
{
    int sum = 0;

    for (int i = 0; i <= 9900; ++i) //전위를 쓰면 프로그램에서 실행하는 단계를 한 단계 건너 뛸수 있다고 옛날에 강사님이 배웠으나, 강사님이 생각하시기에 큰 차이 없다고 하심
    {
        sum += i+100;
    }
    printf("100 부터 10000까지 더한 숫자는 %d 입니다.", sum); 
    return 0;
}

// #include <stdio.h>

// int main(void)
// {
//     int sum = 0;

//     for (int i = 100; i <= 10000; ++i)
//     {
//         sum += i;
//     }
//     printf("100 부터 10000까지 더한 숫자는 %d 입니다.", sum);
//     return 0;
// }