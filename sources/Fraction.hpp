#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

namespace ariel {
    class Fraction{
        int numerator_;
        int denominator_;

    public:
        Fraction(int nume, int deno);
        int getNumerator();
        int getDenominator();
        Fraction operator+(const Fraction& fr1) const;
        Fraction operator/(const Fraction& fr1) const;
        Fraction operator*(const Fraction& fr1) const;
        Fraction operator-(const Fraction& fr1) const;

        friend ostream& operator<<(ostream& os1, const Fraction& fr1);
        friend Fraction operator*(const float& flo,const Fraction& fr2);

        void reduct();
};

}


