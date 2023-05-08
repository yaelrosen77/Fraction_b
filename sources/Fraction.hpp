#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <cctype>
using namespace std;

namespace ariel {
    class Fraction{
        int numerator_;
        int denominator_;

    public:
        Fraction(int nume, int deno);
        Fraction();
        Fraction(const float& val);
        int getNumerator();
        int getDenominator();
        Fraction operator+(const Fraction& fr1) const;
        Fraction operator/(const Fraction& fr1) const;
        Fraction operator*(const Fraction& fr1) const;
        Fraction operator-(const Fraction& fr1) const;
        Fraction operator-(const float& fr1) const;
        Fraction operator*(const float& fr1) const; 
        Fraction operator/(const float& fr1) const;
        Fraction operator+(const float& fr2) const;
        Fraction& operator++();           // prefix increment operator
        Fraction& operator--();           
        Fraction operator++(int);         // postfix increment operator
        Fraction operator--(int);
        bool operator>(const Fraction& fr1) const;
        bool operator<(const Fraction& fr1) const;
        bool operator>=(const Fraction& fr1) const;
        bool operator<=(const Fraction& fr1) const;
        bool operator==(const Fraction& fr1) const;        
        bool operator>(const float& flo) const;
        bool operator<(const float& flo) const;
        bool operator==(const float& flo) const;

        friend ostream& operator<<(ostream& os1, const Fraction& fr1);
        friend Fraction operator*(const float& flo,const Fraction& fr2);
        friend Fraction operator+(const float& flo, const Fraction& fr2);
        friend Fraction operator-(const float& flo,const Fraction& fr2);
        friend Fraction operator/(const float& flo,const Fraction& fr2);
        friend bool operator>(const float& flo, const Fraction& fr2);
        friend bool operator<(const float& flo, const Fraction& fr2);
        friend bool operator>=(const float& flo, const Fraction& fr2);
        friend bool operator<=(const float& flo, const Fraction& fr2);
        friend bool operator==(const float& flo, const Fraction& fr1);
        friend istream& operator>> (istream& in,Fraction& fr11);

        void reduct();
};

Fraction cast_to_frac(const float& flo);


}


