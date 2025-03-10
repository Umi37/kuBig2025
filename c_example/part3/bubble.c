// 랜덤 함수 20 개 프린트
// 정렬 후 프린트
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    for (int i= 20 -1; i >= 1; --i)
        { // i 는 각 스텝의 비교할 횟수
        for (int j = 0; j < i ; ++j)
        {
            if(nums[j]>nums[j+1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < 20 - 1; ++i){
        for (int j = i+1; j < 20; ++j) //j는 비교한 대상의 인덱스 
        {
            if(nums[i]>nums[j]){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    for (int i =0; i < 20; ++i)
    printf("%d, ", nums[i]);
    printf("\n");        
    return 0 ;
}