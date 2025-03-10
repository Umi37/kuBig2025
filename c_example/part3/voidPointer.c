#include <stdio.h>

int main(void)
{
    int i = 100;            // 정수형 변수
    double d = 3.141592;    // 실수형 변수

    void *p; // ✅ void 포인터 선언 (타입이 없는 포인터, 모든 타입의 주소 저장 가능)

   // ✅ p가 i를 가리키도록 설정
    p = &i;
    printf("p 의 주소값은 : %p\n", p);
    printf("p 의 값은 : %d\n\n", *(int*)p); // void 포인터는 역참조 전에 형 변환이 필요함

    // ✅ p가 d를 가리키도록 변경
    p = &d;
    // *p = 6.713; // ❌ 오류: void 포인터는 직접 역참조가 불가능함
    *(double *)p = 6.713; // ✅ 올바른 방식: 역참조 전에 반드시 타입 캐스팅이 필요함
    printf("p 의 주소값은 : %p\n", p);
    printf("p 의 값은 : %f\n\n", *(double*)p);
    return 0;
}