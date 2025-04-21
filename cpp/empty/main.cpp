#include "empty.h"
#include <iostream>

int main()
{
    Empty e1;
    Empty e2 = e1; // 복사 생성자 호출

    e1 = e2 ; 

    Empty *p1 = &e1;    //e1.operator

    const Empty e3;
    const Empty *p2 = &e3;

    return 0;
}