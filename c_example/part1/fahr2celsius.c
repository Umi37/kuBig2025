#include <stdio.h>

int main()
{
    double fahr;
    double celsius ;

    fahr = 200;
    printf("fahr temp : %f \n", fahr);

    celsius = 5.0 / 9.0 * (fahr - 32);
    printf("fahrenheit temp : %f --> celsius temp%f", fahr, celsius);

    return 0;
}