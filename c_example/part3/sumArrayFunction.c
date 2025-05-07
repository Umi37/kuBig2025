// 🚀 배열을 함수에 넘긴 이유
// ✅ 코드의 재사용성을 높이기 위해

// sumArray() 함수를 만들지 않고 main() 내부에서 배열의 합을 구할 수도 있음 
// 하지만, 배열을 함수로 전달하면 여러 곳에서 재사용이 가능해지고, 코드가 더 읽기 쉬워짐
// ✅ 배열의 모든 요소를 반복문을 이용해 처리하기 위해

// sumArray() 함수는 for 문을 사용하여 배열의 각 요소를 하나씩 더함
// 배열을 함수에 전달하면 이 과정이 깔끔하게 분리되므로, main() 함수에서 불필요한 코드가 줄어듦

// ✅ 코드 가독성을 높이기 위해

// sumArray() 함수가 없었다면, main() 함수에서 for 문을 사용해 직접 합을 구해야 했을 것
// 하지만 별도의 함수로 분리하면 main() 코드가 더 깔끔해지고, 읽기 쉬워짐


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ✅ 배열의 합을 구하는 함수 선언
int sumArray(int pArray[], int size);

int main(void)
{
    // ✅ 1. 정수 배열 선언 (초기값 0으로 설정)
    int nums[20] = {0};
    // ✅ 2. 난수 생성기 초기화
    srand(time(NULL));

    // ✅ 3. 배열에 0~100 사이의 랜덤한 숫자 20개를 저장하고 출력
    for(int i=0; i < 20; ++i)
    {
        nums[i] = rand() % 101;
        printf("%d, ", nums[i]);
    }
    printf("\n");

    // ✅ 4. 배열의 요소를 모두 더하는 sumArray() 함수 호출
    int sum = sumArray(nums, sizeof(nums) / sizeof(int));
     // ✅ 5. 배열 요소의 총합 출력
    printf("sum : %d\n", sum);
    return 0;
}

// ✅ sumArray 함수 정의
// 📌 함수 목적: 전달받은 배열의 모든 요소를 더한 값을 반환하는 함수

int sumArray(int pArray[], int size)

    // 20 = sizeof(pArray)/sizeof(int)??
    // 배열을 넘길 때 반드시 주소와 사이즈를 같이 넘겨야 한다.

    // ✅ 배열의 각 요소를 순회하며 sum에 누적
{
        int sum = 0;
    for(int i = 0; i < size; ++i)
    {
        sum += pArray[i]; // 현재 요소를 sum에 더함
    }
    return sum; // 최종 합계를 반환
}