#include <stdio.h>

printArr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int nums[] = {1, 2, 3};
    printArr(nums, 3);  // 배열 이름 = 배열 첫 번째 원소 주소
}
