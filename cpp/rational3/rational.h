#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
private:
    int num; // numerator
    int den; // denominator

public:
    // 생성자, 복사 생성자, 소멸자
    Rational(int num, int den);
    Rational(int num);
    Rational();
    Rational(const Rational& rhs);  // 📌 복사 생성자
    ~Rational();

    // getter/setter
    int getNum();
    int getDen();
    void setNum(int num);
    void setDen(int den);

    // 연산자 오버로딩
    Rational& operator=(const Rational& rhs);  // 복사 대입
    bool operator==(const Rational& rhs);      // 비교
    const Rational operator+(const Rational& rhs); // 덧셈
    const Rational operator-(const Rational& rhs); // 뺄셈

    // 출력 연산자 프렌드 함수
    friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);
};

#endif
