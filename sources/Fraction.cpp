#include "Fraction.hpp"
using namespace ariel;

Fraction :: Fraction(int nume, int deno){
    numerator_ = nume;
    denominator_ = deno;
    reduct();
}

int Fraction :: setNumerator(int num){
    numerator_ = num;
    return numerator_;
}

int Fraction :: setDenominator(int num){
    denominator_ = num;
    return denominator_;
}

Fraction Fraction:: operator*(const Fraction& fr1) const{
    Fraction otro = fr1;
    Fraction res(numerator_*otro.numerator_,denominator_*otro.denominator_);
    return res;
}

Fraction Fraction :: operator/(const Fraction& fr1) const{
    Fraction otro = fr1;
    Fraction res(numerator_*otro.denominator_,denominator_*otro.numerator_);
    return res;
}

Fraction Fraction :: operator+(const Fraction& fr1) const{
    Fraction otro = fr1;
    Fraction res((numerator_*otro.denominator_)+(otro.numerator_*denominator_),denominator_*otro.denominator_);
    return res;
}

Fraction Fraction :: operator-(const Fraction& fr1) const{
    Fraction otro = fr1;
    Fraction res((numerator_*otro.denominator_)-(otro.numerator_*denominator_),denominator_*otro.denominator_);
    return res;
}


ostream& ariel::operator<<(ostream& os1, const Fraction& fr1){
    return os1 << fr1.numerator_ << "/" << fr1.denominator_<<endl;
}

void Fraction :: reduct(){
    if (numerator_ ==0){
        return;
    }
    if (denominator_ == 1 || numerator_ == 1){
        return;
    }
    int nume = abs(numerator_);
    int denom = abs(denominator_);
    int min = std::min(nume, denom);
    int ans; 
    for(int i=1; i<=min; i++){
        if(numerator_%i == 0 && denominator_%i == 0)
            ans = i;
    }
    numerator_ = numerator_ / ans;
    denominator_ = denominator_ / ans;
    if (numerator_<0 && denominator_<0){
        numerator_ *= -1;
        denominator_*= -1;
    }
    if (denominator_<0){
        numerator_*=-1;
        denominator_*=-1;
    }
}

Fraction ariel ::cast_to_frac(const float& flo){
    int num = (int)flo;
    float cpy = flo - (int)flo;
    if (cpy<0){
        cpy*=-1;
    }
    int nume = (int)(cpy*1000);
    Fraction clo(num,1);
    cout<<clo<<endl;
    Fraction dlo(nume,1000);
    cout<<dlo<<endl;
    Fraction res = clo + dlo;
    cout<<res<<endl;
    return res;
}


Fraction operator*(const float& flo,const Fraction& fr2){
    return Fraction(0,1);
}


//first mission is to take the float and turn it into a fraction by extracting its value and the other left value
//later on take the new fraction and multiplying it by the other fraction with the regular function
//