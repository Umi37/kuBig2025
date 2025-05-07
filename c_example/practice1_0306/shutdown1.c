//version 1

#include <stdio.h>

int getTemperature() {

    int num ;
    char ch ;

    printf("온도센서가 현재 온도 감지중...\n");
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
        while (currentTemperature < 100)
        {
            printf("제품이 정상 동작 중 입니다...✅\n");
            currentTemperature = getTemperature();
        
        }
        
    }
    return 0 ;
}