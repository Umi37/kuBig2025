TARGET = helloRaspberry switch_led interrupt led_pwm soft_tone_buzzer hard_tone_buzzer i2c_rgb_led i2c_rgb_led_switch i2c_servo device_gpio fnd_cnt rgb_switch_fnd pir_cnt touch_ATQT1070 temp_humi gyro_cnt trasurebox
all : ${TARGET}
CFLAGS = -lwiringPi -lm

% : %.c
	cc -o $@ $< ${CFLAGS}

clean :
	rm ${TARGET}