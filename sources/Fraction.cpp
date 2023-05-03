#include "Fraction.hpp"
using namespace ariel;

Fraction :: Fraction(int nume, int deno){
    numerator_ = nume;
    denominator_ = deno;
}

int const Fraction :: getNumerator(){
    return numerator_;
}

const int Fraction :: getDenominator(){
    return denominator_;
}


Fraction operator+(const Fraction& fr1, const Fraction& fr2){
    Fraction res((fr1.getNumerator() + fr2.getNumerator()), (fr1.getDenominator() + fr2.getDenominator()));

}