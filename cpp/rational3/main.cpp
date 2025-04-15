#include <iostream>
#include "rational.h"

int main() {
    Rational r1(3, 4);        // 3/4
    Rational r2(2);           // 2/1
    Rational r3;              // 0/1

    Rational r4 = r1;         // 복사 생성자
    r3 = r2 + r1;             // 산술 연산자 +
    r4 = r2 - r1;             // 산술 연산자 -

    if (r1 == r4) {
        std::cout << "r1 and r4 are equal" << std::endl;
    } else {
        std::cout << "r1 and r4 are not equal" << std::endl;
    }

    std::cout << "r1: " << r1 << std::endl;
    std::cout << "r2: " << r2 << std::endl;
    std::cout << "r3: " << r3 << std::endl;
    std::cout << "r4: " << r4 << std::endl;

    return 0;
}
