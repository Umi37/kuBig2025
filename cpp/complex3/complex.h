#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
// class Complex; // 클래스도 함수처럼 이런 식으로 선언할 수도 있음. 
class Complex {
friend std::ostream& operator<<(std::ostream& out, const Complex& rhs); 

private: // attributes
    double re;
    double im;

public: //method
    Complex(double re =0.0, double im=0.0); // Complex(double re, double im); default argument는 뒤쪽부터 줘야 함.
    Complex(const Complex& rhs); 
    ~Complex();

    Complex& operator=(const Complex& rhs);
    bool operator==(const Complex& rhs);
    
    // +, - *
    const Complex operator+(const Complex& rhs); 
    const Complex operator-(const Complex& rhs); 

    //get, set 함수는 아직 안 만듦.
};

#endif