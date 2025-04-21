#include <avr/io.h>
#include <util/delay.h>

int main()
{
    unsigned char led_data;
    led_data = 0x01;
    int direction = 0;
    while (1)
    {
        while(1)
        {
            if(led_data >= 0x0f)
                direction = 0;
            if(led_data == 0)
            {
                direction = 1;
                led_data = 1;
            }

            if (direction)
                led_data >>= 1;
            else
                led_data <<= 1;
            PORTC = led_data;
            _delay_ms(500);
        }
    }
    return 0;
        // led 가 0.5초 마다 좌우로 움직이게 하세요.
        // 1000 -> 0100 -> 0010 -> 0001 -> 0010 -> 0100 -> 처음
}