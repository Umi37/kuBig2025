#include <iostream>
#include "complex.h"

int main()
{
    Complex c1; 
    Complex c2 = 3.0; //Complex c2(3.0); 이렇게 써도 됨.
    Complex c3(3.0, 4.0); 

    // c1.real(c3.real());
    // c1.imag(c3.imag()); 
    c1 = c3; //operator=(c1, c3); //c1.operator=(c3); 둘 중 하나로 바꾸면 위 2줄을 이렇게 직관적으로 바꿀 수 있음. 
    //c1 = &c3; 이렇게 써도 동작은 하지만 일반변수를 주소값으로 치환하는 걸로 보여서 모양이 이상하기 때문에 아래와 같이 씀.  // c1.operator=(&c3); 

    // if (c1.real() == c3.real() && c1.imag() == c3.imag()) 
    if(c1 == c3) // operator=(c1, c3); or c1.operator=(c3);로 컴파일러는 바꿔버림.
    {    std::cout << "c1 and c3 are equal" << std::endl;
    } else {
        std::cout << "c1 and c3 are not equal" << std::endl;
    }

    std::cout << "c1: (" << c1.real() << ", " << c1.imag() << "i)" << std::endl;
    std::cout << "c2: (" << c2.real() << ", " << c2.imag() << "i)" << std::endl;
    std::cout << "c3: (" << c3.real() << ", " << c3.imag() << "i)" << std::endl;
    return 0;
}