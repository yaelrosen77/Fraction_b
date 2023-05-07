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
        Fraction operator+(const Fraction& fr1) const;
        Fraction operator/(const Fraction& fr1) const;
        Fraction operator*(const Fraction& fr1) const;
        Fraction operator-(const Fraction& fr1) const;
        Fraction operator-(const float& fr1);
        Fraction& operator++();           // prefix increment operator
        Fraction& operator--();           
        Fraction operator++(int);         // postfix increment operator
        Fraction operator--(int);
        bool operator>(const Fraction& fr1);
        bool operator<(const Fraction& fr1);
        bool operator>=(const Fraction& fr1);
        bool operator<=(const Fraction& fr1);
        bool operator>(const float& flo);

        friend ostream& operator<<(ostream& os1, const Fraction& fr1);
        friend Fraction operator*(const float& flo,const Fraction& fr2);
        friend Fraction operator+(const Fraction& fr2,const float& flo);
        friend bool operator==(Fraction const& fr1, Fraction const& fr2);
        friend istream& operator>> (Fraction& fr1,istream& in1);
        friend istream& operator>> (istream& in1, Fraction& fr1);

        void reduct();
};

Fraction cast_to_frac(const float& flo);


}


