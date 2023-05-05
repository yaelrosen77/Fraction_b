#include "Fraction.hpp"
using namespace ariel;

Fraction :: Fraction(int nume, int deno){
    numerator_ = nume;
    denominator_ = deno;
}

int Fraction :: getNumerator(){
    return numerator_;
}

int Fraction :: getDenominator(){
    return denominator_;
}

Fraction operator+ (const Fraction& fr1, const Fraction& fr2){
    Fraction uno = fr1;
    Fraction dos = fr2;
    Fraction res(uno.getNumerator()+dos.getNumerator(),uno.getDenominator() + dos.getDenominator());
}

void Fraction :: reduct(){
    int min = std::min(numerator_, denominator_);
    int ans; 
    for(int i=1; i<=min; i++){
        if(numerator_%i == 0 && denominator_%i == 0)
            ans = i;
    }
    numerator_ = numerator_ / ans;
    denominator_ = denominator_ / ans;
}