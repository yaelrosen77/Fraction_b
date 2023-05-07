#include "Fraction.hpp"
using namespace ariel;

Fraction :: Fraction(int nume, int deno){
    numerator_ = nume;
    denominator_ = deno;
    reduct();
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
    Fraction dlo(nume,1000);
    Fraction res = clo + dlo;
    return res;
}


Fraction ariel:: operator*(const float& flo,const Fraction& fr2){
    Fraction casti = cast_to_frac(flo);
    Fraction res = casti * fr2;
    return res;
}

Fraction ariel:: operator+(const Fraction& fr2, const float& flo){
    Fraction casti = cast_to_frac(flo);
    Fraction res = casti + fr2;
    return res;
}

Fraction Fraction:: operator-(const float& fr1){
    Fraction flo = cast_to_frac(fr1);
    Fraction res = *this - flo;
    return res;
}

Fraction& Fraction :: operator++(){
    numerator_ += denominator_;
    reduct();
    return *this;
}           

Fraction& Fraction :: operator--(){
    numerator_ -= denominator_;
    reduct();
    return *this;
}           
        
Fraction Fraction :: operator++(int){
    Fraction tmp(numerator_,denominator_);
   ++(*this);
   return tmp;
}        

Fraction Fraction :: operator--(int){
    Fraction tmp(numerator_,denominator_);
    --(*this);
   return tmp;
} 

bool ariel :: operator==(Fraction const& fr1, Fraction const& fr2){
    if (fr1.numerator_ == fr2.numerator_ && fr1.denominator_ == fr2.denominator_){
        return true;
    }
    return false;
}

bool Fraction :: operator>(const Fraction& fr1){
    if (*this == fr1){
        return false;
    }
    if (denominator_ == fr1.denominator_){
        if (numerator_<fr1.numerator_){
            return false;
        }
        return true;
    }
    if (denominator_>fr1.denominator_ && numerator_<fr1.numerator_){
        return false;
    }
    if (denominator_<fr1.denominator_ && numerator_>fr1.numerator_){
        return true;
    }
    int nume1 = numerator_*fr1.denominator_;
    int nume2 = fr1.numerator_*denominator_;

    if (nume2 > nume1){
        return false;
    }
    return true;
}

bool Fraction :: operator<(const Fraction& fr1){
    if (*this == fr1){
        return false;
    }
    return !(*this>fr1);
}

bool Fraction :: operator>=(const Fraction& fr1){
    if (*this == fr1 || *this>fr1){
        return true;
    }
    return false;
}

bool Fraction :: operator<=(const Fraction& fr1){
    if (*this == fr1 || *this<fr1){
        return true;
    }
    return false;
}

bool Fraction :: operator>(const float& flo){
    Fraction c = cast_to_frac(flo);
    return (*this>c);
}