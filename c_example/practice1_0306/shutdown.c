//version 2

#include <stdio.h>

int getTemperature() {
    int num;
    printf("온도센서가 현재 온도 감지중...\n");  // ✅ 메시지 유지!
    printf("현재 온도를 입력하세요: ");
    scanf("%d", &num);
    return num;
}

int main(void) {
    int currentTemperature = getTemperature();  // 초기 온도 측정

    printf("현재 온도: %d°C\n", currentTemperature);

    if (currentTemperature >= 100) {
        printf("⚠️ 과열 감지! 시스템을 종료합니다.\n");
        return 0;  // 시스템 종료
    } else {
        while (currentTemperature < 100) {
            printf("제품이 정상 동작 중입니다...✅\n");
            
            // ✅ 계속 온도 입력받기
            currentTemperature = getTemperature();
        }
        printf("⚠️ 과열 감지! 시스템을 종료합니다.\n");
    }

    return 0;
}
