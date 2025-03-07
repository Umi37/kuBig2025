#include <stdio.h>

// 가상의 온도 센서에서 현재 온도를 가져오는 함수 (실제 시스템에서는 센서에서 값을 읽음)
int getTemperature() {

    int num ;
    char ch ;

    printf("온도센서가 현재 온도 감지중...");
    scanf("%c",&ch);
    
    if (ch == '\n') {
        printf("현재 온도를 입력하세요: ");
    }
    scanf("%d",&num);
    return num;  
}

int main(void) {
    int currentTemperature = getTemperature();  // 온도 센서에서 값 읽기

    printf("현재 온도: %d°C\n", currentTemperature);

    if (currentTemperature >= 100) {
        printf("⚠️ 과열 감지! 시스템을 종료합니다.\n");
        return 0;  // 전자제품의 동작을 멈춤
    }

    else {
        printf("✅ 정상 동작 중\n");
    }
    return 0 ;
}