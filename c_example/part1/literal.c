#include <stdio.h>

int main(void){
    printf("%d %d %d\n", 100, 0144, 0x64); //0x 는 진법을 바꾸겠다. (16진법)
    printf("%d 0%o 0x%x\n", 100, 100, 100); //%o는 8진법

    printf("%lldLL\n", 10000000000LL); //숫자가 굉장히 클때 (int의 범위를 벗어나게 되면 LL타입으로)

    printf("%f %f\n", 2.718, 3.141592F); 
    printf("%d %d %d\n", 'A', 'a', '0');
    printf("%c %c %c\n", 65, 97, 48);
    printf("%c %c %c\n", 'a', 'a' +1, 'A' +2);

    printf ("%s\n", "ABCD");

    return 0;

    
}