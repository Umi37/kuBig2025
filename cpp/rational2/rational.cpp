#include <cassert>
#include "rational.h"

Rational::Rational(int num, int den) {
    assert(den != 0);
    this->num = num;
    this->den = den;
}

Rational::Rational(int num) {
    this->num = num;
    this->den = 1;
}

Rational::Rational() {
    this->num = 0;
    this->den = 1;
}

Rational::~Rational() {
    // nothing special
}

int Rational::getNum() {
    return this->num;
}

int Rational::getDen() {
    return this->den;
}

void Rational::setNum(int num) {
    this->num = num;
}

void Rational::setDen(int den) {
    if (den != 0) {
        this->den = den;
    }
}

// 📌 복사 대입 연산자
Rational& Rational::operator=(const Rational& rhs) {
    this->num = rhs.num;
    this->den = rhs.den;
    return *this;
}

// 📌 비교 연산자
bool Rational::operator==(const Rational& rhs) {
    return (this->num * rhs.den == rhs.num * this->den);  // 통분 비교
}
