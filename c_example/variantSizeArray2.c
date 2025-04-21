#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int size;
    scanf("%d", &size);

    int *pArr = malloc(sizeof(int) * size); // 힙에 공간 할당 -> 힙상에 할당된 공간 주소값이 결과값

    for (int i = 0; i < size; ++i) {
        // *(pArr + i) = i + 1;
        pArr[i] = i + 1;
    }

    for (int i = 0; i < size; ++i) {
        // printf("%d ", *(pArr + i));
        printf("%d ", pArr[i]);     // 포인터를 가지고 배열식을 써도 된다.
    }
    printf("\n");
    free(pArr);
    return 0;
}