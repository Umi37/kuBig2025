#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
    int num;    // numerator
    int den;    // denominator

public:
    Rational(int num, int den);  // full constructor
    Rational(int num);           // implicit constructor
    Rational();                  // default constructor
    ~Rational();                 // destructor

    int getNum();
    int getDen();

    void setNum(int num);
    void setDen(int den);

    Rational& operator=(const Rational& rhs);  // 복사 대입 연산자
    bool operator==(const Rational& rhs);      // 비교 연산자
};

#endif
