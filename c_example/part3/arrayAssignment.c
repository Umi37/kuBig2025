#include <stdio.h>

int main(void)
{
    int nums1[] = {1, 2, 3, 4, 5};
    int nums2[5];

    // nums2 = nums1; nums2 는 상수라서? 상수처럼 동작해서? 이렇게 값을 넣을 수 없다?
    for (int i = 0; i<5; ++i)
    {
        nums2[i] = nums1[i];
    }
    printf("nums1 의 주소값 : %p\n", &nums1[0]); //    printf("nums1 의 주소값 : %p", nums1); 그냥 이름만 써도 됨
    printf("nums2 의 주소값 : %p\n", &nums2[0]);
    // 주소값이 다르다는 것은 서로 독립적인 메모리이다.
    nums2[3] = 14;
    // shallow copy
    int *nums3;
    nums3 = &nums1[0];
    printf("nums3 의 주소값 %p\n\n", nums3);
    nums3[2] = 23;
    for (int i = 0; i<5; ++i)
    {
        printf("nums1 %d : %d \n", i, nums1[i]);
        printf("nums2 %d : %d \n", i, nums2[i]);
        printf("nums3 %d : %d \n", i, nums3[i]);
    }

   return 0;
}