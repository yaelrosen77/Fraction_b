#include "Fraction.hpp"
using namespace ariel;

Fraction :: Fraction(int nume, int deno){
    if (deno==0){
        __throw_invalid_argument("Division by zero");
    }
    numerator_ = nume;
    denominator_ = deno;
    reduct();
}

Fraction :: Fraction(const float& val){
    *this = cast_to_frac(val);
}

Fraction :: Fraction(){
    numerator_ = 0;
    denominator_ =1;
}

int Fraction:: getNumerator(){
    return numerator_;
}

int Fraction:: getDenominator(){
    return denominator_;
}

Fraction Fraction:: operator*(const Fraction& fr1) const{
    Fraction otro = fr1;
    Fraction res(numerator_*otro.numerator_,denominator_*otro.denominator_);
    return res;
}

Fraction Fraction :: operator/(const Fraction& fr1) const{
    if (fr1.numerator_ == 0){
        __throw_invalid_argument("Division by zero");
    }
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
    return os1 << fr1.numerator_ << "/" << fr1.denominator_;
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
    int nume = flo*1000;
    Fraction res(nume,1000);
    return res;
}

Fraction Fraction:: operator+(const float& flo) const{
    Fraction casti(flo);
    Fraction res = casti + *this;
    return res;
}

Fraction Fraction:: operator*(const float& flo) const {
    Fraction casti(flo);
    Fraction res = casti * *this;
    return res;
}

Fraction Fraction:: operator/(const float& flo) const{
    Fraction casti(flo);
    if (casti.numerator_ == 0){
        __throw_invalid_argument("Division by zero");
    }
    Fraction res = *this / casti;
    return res;
}

Fraction Fraction:: operator-(const float& fr1) const{
    Fraction flo(fr1);
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

bool Fraction:: operator==(const Fraction& fr1) const{
    if (numerator_==fr1.numerator_ && denominator_== fr1.denominator_)
        return true;
    return false;
}

bool Fraction :: operator>(const Fraction& fr1)const {
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

bool Fraction :: operator<(const Fraction& fr1)const {
    if (*this == fr1){
        return false;
    }
    return !(*this>fr1);
}

bool Fraction :: operator>=(const Fraction& fr1)const{
    if (*this == fr1 || *this>fr1){
        return true;
    }
    return false;
}

bool Fraction :: operator<=(const Fraction& fr1) const{
    if (*this == fr1 || *this<fr1){
        return true;
    }
    return false;
}

bool Fraction :: operator>(const float& flo)const{
    Fraction c(flo);
    return (*this>c);
}

bool Fraction :: operator<(const float& flo)const{
    Fraction c(flo);
    return *this<c;
}

bool Fraction :: operator==(const float& flo) const{
    Fraction fl1(flo);
    return *this==fl1;
}

Fraction ariel::operator+(const float& flo, const Fraction& fr2){
    return fr2+flo;
}

Fraction ariel::operator-(const float& flo, const Fraction& fr2){
    Fraction res = -1*(fr2-flo);
    return res;
}

Fraction ariel::operator*(const float& flo, const Fraction& fr2){
    return fr2*flo;
}

Fraction ariel::operator/(const float& flo, const Fraction& fr2){
    if (fr2.numerator_ == 0){
        __throw_invalid_argument("Division by zero");
    }
    Fraction res = fr2/flo;
    int nume = res.numerator_;
    int denom = res.denominator_;
    res.numerator_ = denom;
    res.denominator_ = nume;
    return res;
}

bool ariel::operator>(const float& flo, const Fraction& fr2){
    return Fraction(flo)>fr2;
}
bool ariel::operator<(const float& flo, const Fraction& fr2){
    return Fraction(flo)<fr2;
}
bool ariel::operator>=(const float& flo, const Fraction& fr2){
    return Fraction(flo)>=fr2;
}
bool ariel::operator<=(const float& flo, const Fraction& fr2){
    return Fraction(flo)<=fr2;
}

bool ariel::operator==(const float& flo, const Fraction& fr1){
    return fr1==flo;
}

istream& ariel :: operator>> (istream& in1,Fraction& fr1){
    int nume, denom;    
    string input; 
    string num = "";
    string deno = "";
    getline(in1,input);
    bool sign = false;
    if ((input.find(".")== input.npos) && (input.find(" ") == input.npos) && (input.find("/") == input.npos) && (input.find(",") == input.npos)){
        __throw_bad_function_call();
        exit(1);
    }
    for (char c : input){
        if (sign == false){
            if (isdigit(c))
                num+=c;
            else {
                if (c!= '.' && c!= ' ' && c!= '/' && c!= ','){
                    __throw_invalid_argument("Cannot create a fraction with undefined chars");
                    exit(1);
                }
                sign = true;
            }
        }
        else {
            if (isdigit(c))
                deno+=c;
            else{
                __throw_invalid_argument("Cannot create a fraction with undefined chars");
                exit(1);
            }
        }
    }
    nume = stoi(num);
    denom = stoi(deno);
    fr1.numerator_ = nume;
    fr1.denominator_= denom;
    return in1;
}