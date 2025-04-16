#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
    int num_; // numerator
    int den_; // denominator

public:
    Rational(int num = 0, int den = 1); // 생성자

    // Getter
    int getNum() const;
    int getDen() const;

    // Setter
    void setNum(int num);
    void setDen(int den);

    // 사칙 연산자
    const Rational operator+(const Rational& rhs) const;
    const Rational operator-(const Rational& rhs) const;
    const Rational operator*(const Rational& rhs) const;
    const Rational operator/(const Rational& rhs) const;

    // 복합 대입 연산자
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);

    // 비교 연산자
    bool operator==(const Rational& rhs) const;
    bool operator!=(const Rational& rhs) const;

    // 증가 연산자
    Rational& operator++();      // prefix
    Rational operator++(int);    // postfix
};

#endif
