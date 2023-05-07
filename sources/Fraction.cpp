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

Fraction cast_to_frac(const float& flo){
    bool booli = false;
    int nume = 0;
    int counter = 0;
    float cpy = flo;
    if (flo<0){
        booli = true;
        cpy *= -1;
    }
    Fraction clo(0,1);
    Fraction dlo(0,1);
    if (cpy>=1){
        clo.setNumerator((int)flo);
        cpy = cpy - (int)cpy;
    }
    cpy*=10;
    while (cpy>0){
        nume *=10;
        counter++;
        nume += (int)cpy;
        cpy = cpy - (int)cpy;
        cpy*=10;
    }
    if (booli==true){
        nume*= -1;
    }
    dlo.setDenominator(pow(10,counter));
    dlo.setNumerator(nume);
    Fraction res = clo +dlo;
    return res;
}



Fraction operator*(const float& flo,const Fraction& fr2){
    
}


//first mission is to take the float and turn it into a fraction by extracting its value and the other left value
//later on take the new fraction and multiplying it by the other fraction with the regular function
//