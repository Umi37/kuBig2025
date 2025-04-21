#include <iostream>
#include"complex.h"

int main() 
{
    Complex c1;
    Complex c2 = 3.0;
    Complex c3(3.0, 4.0);
    Complex c4 = c3; // copy constructor
    
    c1 = c3; // c1.opertatior=(c3) or operator=(c1, c3)

    if(c1==c3){
        std::cout << "c1 and c3 are equal" << std::endl;
    } else {std::cout << "c1 and c3 are not equal" << std::endl;
    }

    c4 = c2 + c3; //c2.operator+(c3) or operator+(c2, c3)
    c4 = c2 - c3;

    //std::cout << c1; //(3.0, 4.0) std::cout.operatior<<(c1) or operator<<(std::cout, c1) 
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << c3 << std::endl; 
    std::cout << c4 << std::endl;

    return 0;
}

