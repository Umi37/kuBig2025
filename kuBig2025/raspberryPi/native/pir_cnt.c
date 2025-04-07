// cc helloRaspberry.c -lwiringPi

#include <stdio.h>
#include <wiringPi.h>

// gpio pin
#define PIR_PIN 7
#define LED1_PIN 23

void SW_ISR1(void);

int main(void)
{
    wiringPiSetupGpio(); // BCM 기준 gpio 핀번호
    wiringPiISR(PIR_PIN, INT_EDGE_BOTH, SW_ISR1);

    pinMode(LED1_PIN, OUTPUT);
    pinMode(PIR_PIN, INPUT);

    while (1)
    {
        if(digitalRead(PIR_PIN) == HIGH)
        {
            printf("PIR 감지");
        }
        delay(100);
    }
    return 0;
}

void SW_ISR1(void)
{

        printf("PIR ON\n");
        digitalWrite(LED1_PIN, HIGH);
        delay(300);
        digitalWrite(LED1_PIN, LOW);
    }