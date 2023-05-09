#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>                //certain operations such as abs.. 
#include <string.h>
#include <cctype>               // provides functions and macros for character classification and manipulation
#include <limits>               // for retrieving the maximum and minimum values fof respective data types
using namespace std;

namespace ariel {
    class Fraction{
        int numerator_;
        int denominator_;
        void reduct();

    public:
        Fraction(int nume =0, int deno=1);       
        Fraction(double val);
        int getNumerator();
        int getDenominator();
        void setNumerator(int elm);
        void setDenominator(int elm);
        Fraction operator+(const Fraction& fr1) const;
        Fraction operator/(const Fraction& fr1) const;
        Fraction operator*(const Fraction& fr1) const;
        Fraction operator-(const Fraction& fr1) const;
        Fraction operator-(const float& fr1) const;
        Fraction operator*(const float& flo) const; 
        Fraction operator/(const float& fr1) const;
        Fraction operator+(const float& flo) const;
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
        friend istream& operator>> (istream& in1,Fraction& fr11);
};
Fraction cast_to_frac(const float& flo);                    //A function that casts a float to a fraction

}


