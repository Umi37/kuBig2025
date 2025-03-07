// unsigned char attr; 8bit 8개 속성 
// 비트 연산
// 마스킹 효과 이해하기

#include <stdio.h>
// 볼드 1 자리 비트         0b00000001
// 이탈릭 2 자리 비트       0b00000010
// 쉐도우 3 자리 비트       0b00000100
// 언더라인 4 자리 비트     0b00001000
// 볼드 이면서 언더라인     0b00001001

int main(void)
{
        unsigned char attr;         // 8bit 8개 속성
        attr = attr ^ attr;         // 모두 0 으로 설정
        attr = attr | 0b00000001;    // attr 볼드로 설정
        printf("attr: 0x%02x\n", attr);
        attr = attr | (0b00000010 + 0b00000100) ; // attr 이탈릭, 쉐도우 추가
        printf("attr: 0x%02x\n", attr);
        attr + attr & (~0b00000001); //볼드비트로 된 첫번째 비트가 제거가 됨
        printf("attr: 0x%02x\n", attr);


    return 0;
    
}