#include "complex.h"

Complex::Complex()
{
    this->re = 0.0; 
    this->im = 0.0; 
}

Complex::Complex(double re)
{
    this->re = re;
    this->im = 0.0; 
}

Complex::Complex(double re, double im)
{
    this->re = re; 
    this->im = im; 
}

Complex::~Complex()
{

} 

// void Complex::operator=(Complex c)
// {
//     this->re = c.re; 
//     this->im = c.im; 
// }

// void Complex::operator=(const Complex *pc)
// {
//     this->re = pc->re; 
//     this->im = pc->im; 
// }

void Complex::operator=(const Complex& rc)
{
    this->re = rc.re; 
    this->im = rc.im; 
}

bool Complex::operator==(const Complex& rc)
{
    // if (this->re == rc.re && this->im == rc.im) {
    //     return true; 
    // } else {
    //     return false;
    // }
    return (this->re == rc.re && this->im == rc.im); // 어차피 식의 결과값이 true, false이므로 if, else 안 쓰고 막바로 반환하는 게 더 간결함.
}

double Complex::real()
{
    return this->re; 
}

double Complex::imag()
{
    return this->im; 
}

void Complex::real(double re)
{
    this->re = re; 
}

void Complex::imag(double im)
{
    this->im = im; 
}