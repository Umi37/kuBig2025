#include <stdio.h>

int add(int a, int b){
    return a + b;
}

int substract(int a, int b)
{
    return a - b;
}

int main(void)
{
    int x = 9;
    int y = 6;
    printf("add(x,y) : %d\n", add(x, y));
    printf("substract(x, y) : %d\n\n", substract(x, y));
    
    
    //함수포인터 선언
    int (*fp)(int, int);
    // fp = &add; // 함수의 주소를 포인터에 연결
    fp = add; // 함수의 주소를 포인터에 연결 (이름 자체만 써도 연결됨)
    printf("add(x, y) : %d\n", (*fp)(x, y)); //함수 포인터를 역참조
    fp = &substract;
    printf("substract(x, y) : %d\n", fp(x,y));

    return 0;
}