#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:            // implemetation 내부 구현 - 멤버 변수
    double re;      // real part (실수부)
    double im;      // imaginary part (허수부)

public:             // interface - 멤버 함수
    Complex(double re, double im);      // constructor
    Complex(double re);
    Complex();                          // function overloading (함수 중복) - C언어에서는 함수의 중복 허용 불가, C++ 에서는 함수의 이름, 인자의 타입, 인자의 갯수로 함수 특정하므로 가능
    ~Complex();                         // destructor

    double real();
    double imag();

    void real(double re);
    void imag(double im);

};



#endif
