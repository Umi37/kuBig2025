#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <softTone.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define MPU_ADDR 0x68
#define BUZZER_PIN 12

#define RGB_I2C_ADDR 0x5e
#define PCA9685_LED_ON_L 0x06
#define PCA9685_MODE1 0x00
#define PCA9685_PRESCALE 0xFE

void i2c_rgb_init(int fd);
void set_rgb(int fd, int r, int g, int b);

int main(void)
{
    wiringPiSetupGpio();

    // I2C 초기화
    int mpu_fd = wiringPiI2CSetup(MPU_ADDR);
    int rgb_fd = wiringPiI2CSetup(RGB_I2C_ADDR);
    wiringPiI2CWriteReg8(mpu_fd, 0x6B, 0); // MPU6050 슬립 해제
    i2c_rgb_init(rgb_fd);

    // 부저
    softToneCreate(BUZZER_PIN);

    while (1)
    {
        int16_t ax = (wiringPiI2CReadReg8(mpu_fd, 0x3B) << 8) | wiringPiI2CReadReg8(mpu_fd, 0x3C);
        int16_t ay = (wiringPiI2CReadReg8(mpu_fd, 0x3D) << 8) | wiringPiI2CReadReg8(mpu_fd, 0x3E);
        int16_t az = (wiringPiI2CReadReg8(mpu_fd, 0x3F) << 8) | wiringPiI2CReadReg8(mpu_fd, 0x40);

        float acc_total = sqrt(ax * ax + ay * ay + az * az);

        if (fabs(acc_total - 16384) > 1000) // 움직임 감지 기준
        {
            // 보물상자가 깨어난다
            printf("움직임 감지됨! 보물상자가 반응합니다.\n");

            set_rgb(rgb_fd, 4095, 0, 0);     // 빨강
            softToneWrite(BUZZER_PIN, 659); // E음
            delay(200);

            set_rgb(rgb_fd, 0, 4095, 0);     // 초록
            softToneWrite(BUZZER_PIN, 784); // G음
            delay(200);

            set_rgb(rgb_fd, 0, 0, 4095);     // 파랑
            softToneWrite(BUZZER_PIN, 880); // A음
            delay(200);

            // 소리 & 불빛 끄기
            set_rgb(rgb_fd, 0, 0, 0);
            softToneWrite(BUZZER_PIN, 0);
        }

        delay(100);
    }

    return 0;
}

void i2c_rgb_init(int fd)
{
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0x10);
    delay(10);
    wiringPiI2CWriteReg8(fd, PCA9685_PRESCALE, 0x79); // 50Hz
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0xA1);
}

void set_rgb(int fd, int r, int g, int b)
{
    wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L + 2, r);
    wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L + 6, g);
    wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L + 10, b);
}
