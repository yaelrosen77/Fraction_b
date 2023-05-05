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
        void reduct();
};

Fraction operator+(const Fraction& fr1, const Fraction& fr2);           //symetrical operators are usually declared outside the class

}


///after that create a function that reduces the fraction 
///after that trying to run just the plus