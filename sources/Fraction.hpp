#pragma once
#include <iostream>
using namespace std;

namespace ariel {
    class Fraction{
        int numerator_;
        int denominator_;
    

    public:
        Fraction(int nume, int deno);
        int const getNumerator();
        const int getDenominator();
};

Fraction operator+(const Fraction& fr1, const Fraction& fr2);           //symetrical operators are usually declared outside the class






}



///next phase is to check what is the problem with the function and fix it by changing the method to const. 
///after that create a function that reduces the fraction 
///after that trying to run just the plus