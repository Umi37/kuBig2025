#include <iostream>
#include "rational.h"

int main() {
    Rational r1(3, 4);      // 3/4
    Rational r2(3);         // 3/1
    Rational r3;            // 0/1

    r3 = r1;  // 복사 대입 연산자 사용

    if (r1 == r3) {  // 비교 연산자 사용
        std::cout << "r1 and r3 are equal" << std::endl;
    } else {
        std::cout << "r1 and r3 are not equal" << std::endl;
    }

    std::cout << "r1 : " << r1.getNum() << "/" << r1.getDen() << std::endl;
    std::cout << "r2 : " << r2.getNum() << "/" << r2.getDen() << std::endl;
    std::cout << "r3 : " << r3.getNum() << "/" << r3.getDen() << std::endl;

    return 0;
}
