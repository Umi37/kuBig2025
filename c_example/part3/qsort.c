// 랜덤 함수 20 개 프린트
// qsort 정렬 후 프린트
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b); // a 와 b 중 어느게 더 큰지 비교해서 값을 보내려고 이 수식을 씀 ( 양수면 앞에 것이 더 크고 음수면 뒤에 것이 더 큰걸 테니까)
}    // void 타입인데 - 오퍼레이터를 쓸수 있느냐? void 는 오퍼레이트 타입이 정해져있지 않아서 타입캐스팅을 해야함

int main(void)
{
    int nums[20] = {0}; // 이 코드에서는 0으로 초기화 하지 않아도 되지만, 습관을 들이는 것이 좋다 (코드에 따라 가비지값이 들어갈 수가 있음) 
                        // null 로 초기화 하는 자료형은 캐릭터???
    srand(time(NULL)); //time 이라는 함수가 항상 양수의 난수를 생성하게함 unsigned int 하지 않아도
    for (int i = 0; i < 20; ++i)
    {
        nums[i] = rand() % 101;
    }
    for (int i =0; i < 20; ++i)
        printf("%d, ", nums[i]);
    printf("\n");

    // bubble sorting
    qsort(nums, 20, sizeof(nums[0]), compare);

    for (int i =0; i < 20; ++i)
    printf("%d, ", nums[i]);
    printf("\n");        
    return 0 ;
}