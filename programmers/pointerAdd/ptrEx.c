#include <stdio.h>

int main(void) {
    // 주소값을 직접 대입 (주의! 하드코딩된 주소)
    int *a = (int *)0x5f4976312008;

    printf("a points to: %p\n", a);

    // 조심: 이건 읽기 시도 → 위험!
    // printf("*a = %d\n", *a);  // ❌ 실행하면 세그멘테이션 오류 가능

    return 0;
}
  