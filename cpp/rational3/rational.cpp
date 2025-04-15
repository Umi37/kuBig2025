#include <cassert>
#include <iostream>
#include "rational.h"

// 생성자들
Rational::Rational(int num, int den) { // 일반적인 분수 생성
    assert(den != 0);
    this->num = num;
    this->den = den;
}

Rational::Rational(int num) {           // 정수 입력 시 자동으로 분모를 1로 설정
    this->num = num;
    this->den = 1;
}

Rational::Rational() {                  // 기본값 0/1로 초기화
    this->num = 0;
    this->den = 1;
}

// 📌 복사 생성자 (다른 Rational 객체로부터 복사)
Rational::Rational(const Rational& rhs) {
    this->num = rhs.num;
    this->den = rhs.den;
}

Rational::~Rational() {
    // nothing special
}

// getter/setter
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
    return (this->num * rhs.den == rhs.num * this->den);
}

// 📌 덧셈 연산자
const Rational Rational::operator+(const Rational& rhs) {
    int n = this->num * rhs.den + rhs.num * this->den;
    int d = this->den * rhs.den;
    return Rational(n, d);
}

// 📌 뺄셈 연산자
const Rational Rational::operator-(const Rational& rhs) {
    int n = this->num * rhs.den - rhs.num * this->den;
    int d = this->den * rhs.den;
    return Rational(n, d);
}

// 📌 출력 연산자
std::ostream& operator<<(std::ostream& out, const Rational& rhs) {
    out << rhs.num << "/" << rhs.den;
    return out;
}
