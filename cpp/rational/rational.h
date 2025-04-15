#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
    int num;    // numerator (분자)
    int den;    // denominator (분모)

public:
    Rational(int num, int den);  // 두 값을 다 주는 생성자
    Rational(int num);           // 정수 하나만: 분모는 1
    Rational();                  // 기본 생성자: 0/1
    ~Rational();

    int getNum();
    int getDen();

    void setNum(int num);
    void setDen(int den);
};

#endif