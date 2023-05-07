#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
using namespace std;

namespace ariel {
    class Fraction{
        int numerator_;
        int denominator_;

    public:
        Fraction(int nume, int deno);
        int setNumerator(int num);
        int setDenominator(int num);
        Fraction operator+(const Fraction& fr1) const;
        Fraction operator/(const Fraction& fr1) const;
        Fraction operator*(const Fraction& fr1) const;
        Fraction operator-(const Fraction& fr1) const;

        friend ostream& operator<<(ostream& os1, const Fraction& fr1);
        friend Fraction operator*(const float& flo,const Fraction& fr2);

        void reduct();
};

Fraction cast_to_frac(const float& flo);


}


