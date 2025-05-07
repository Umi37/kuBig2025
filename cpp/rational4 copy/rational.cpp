#include "rational.h"
#include <cassert>

// 최대공약수 구하는 유틸 함수
static int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// 약분 함수
void Rational::reduce() {
    int g = gcd(num_, den_);
    if (g != 0) {
        num_ /= g;
        den_ /= g;
    }
    // 음수는 분자에만
    if (den_ < 0) {
        num_ = -num_;
        den_ = -den_;
    }
}

// 생성자
Rational::Rational(int num, int den) : num_(num), den_(den) {
    assert(den != 0);
    reduce();
}

// Getter/Setter
int Rational::getNum() const { return num_; }
int Rational::getDen() const { return den_; }

void Rational::setNum(int num) {
    num_ = num;
    reduce();
}
void Rational::setDen(int den) {
    assert(den != 0);
    den_ = den;
    reduce();
}

// 연산자
const Rational Rational::operator+(const Rational& rhs) const {
    return Rational(num_ * rhs.den_ + rhs.num_ * den_, den_ * rhs.den_);
}

const Rational Rational::operator-(const Rational& rhs) const {
    return Rational(num_ * rhs.den_ - rhs.num_ * den_, den_ * rhs.den_);
}

const Rational Rational::operator*(const Rational& rhs) const {
    return Rational(num_ * rhs.num_, den_ * rhs.den_);
}

const Rational Rational::operator/(const Rational& rhs) const {
    assert(rhs.num_ != 0);
    return Rational(num_ * rhs.den_, den_ * rhs.num_);
}

// 복합 대입
Rational& Rational::operator+=(const Rational& rhs) {
    *this = *this + rhs;
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
    *this = *this - rhs;
    return *this;
}

// 비교
bool Rational::operator==(const Rational& rhs) const {
    return num_ == rhs.num_ && den_ == rhs.den_;
}
bool Rational::operator!=(const Rational& rhs) const {
    return !(*this == rhs);
}

// 증가 연산자
Rational& Rational::operator++() {
    *this += Rational(1);
    return *this;
}

Rational Rational::operator++(int) {
    Rational tmp = *this;
    ++(*this);
    return tmp;
}

// 출력 연산자
std::ostream& operator<<(std::ostream& out, const Rational& rhs) {
    out << rhs.num_ << "/" << rhs.den_;
    return out;
}
