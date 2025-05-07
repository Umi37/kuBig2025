#include <cassert>
#include "rational.h"

void Rational::reduce()
{
    int g = gcd(num_, den_);
    num_ = num_ / g;
    den_ = den_ / g;
}

Rational::Rational(int num, int den)
: num_(num), den_(den)
{
    assert(den );

        this->reduce();
}