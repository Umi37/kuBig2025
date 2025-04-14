#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
public: 
    Complex(); //default constructor 입력값이 없는 생성자  
    Complex(double re); //convert constructor 값이 하나인 생성자   
    Complex(double re, double im); //constructor
    ~Complex(); //destructor

    // void operator=(Complex c); //실제로 치환된 값이 반환값이니까 void라고 쓰면 안 되지만 반환형은 내일 배울 거라서 임의로 void로 해놓음. 오버헤드 문제 
    // void operator=(const Complex *pc); //포인터
    void operator=(const Complex& rc); //레퍼런스를 써서 해결하자! 

    // int operator==(const Complex& rc); // 참이면 1, 거짓이면 0을 반환하므로 반환형은 int
    bool operator==(const Complex& rc); // c++에는 논리형 bool이 있으므로 ㅇㅇ

    double real();
    double imag();

    void real(double re);
    void imag(double im);

private: 
    double re; 
    double im; 
};

#endif
