#include <stdio.h>

void modify(int a) {
    a = 4;
}

int main(void)
{
    int a = 1;
    modify(a);

    printf("a는 %d다.\n", a);

    return 0;
}