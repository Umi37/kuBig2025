#include <stdio.h>

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5};
    int *p;

    p = nums; // 배열의 이름은 첫번째 배열의 주소값과 같다. 상수와 같다. // &nums[0] 이렇게 써도 작동은 된다고? 왜?
    for (int i = 0; i < 5; ++i)
    {
        printf("%d 번째 원소는 : %d\n", i, nums[i]);
        printf("%d 번째 원소는 : %d\n", i, p[i]);
        printf("%d 번째 원소는 : %d\n", i, *(p + i)); //포인터가 차지하고 있는 바이트 수만큼 뒤쪽 포인터가 더해진다고???
    }
}