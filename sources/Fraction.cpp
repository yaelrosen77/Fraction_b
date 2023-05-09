#include "Fraction.hpp"
using namespace ariel;


/*A parameterized constructor that takes two arguments- a numerator and denominator.
Throws exception if getting illegal denominator.
It creates a reducted fraction, while any negative sign is always displays at the numerator side.*/
Fraction :: Fraction(int nume, int deno){
    if (deno==0){
        throw invalid_argument("Division by zero");
    }
    numerator_ = nume;
    denominator_ = deno;
    reduct();
}

/*A parameterized constructor that takes one argument - a float type.
does not throw any arithmetic exception and consider the zero as 0/1000;
creates a reducted fraction that uses up to 3 digits beyond the desimal point for acuracy.
*/
Fraction :: Fraction(double val){
    *this = cast_to_frac(val);
}
int Fraction:: getNumerator(){
    return numerator_;
}

int Fraction:: getDenominator(){
    return denominator_;
}
        
void Fraction :: setNumerator(int a){
    numerator_ = a;
    reduct();
}

/*Set denominator assuming the given argument is different from zero.
throws exception if the given value is zero. 
it changes the fraction to be also a reducted one.*/
void Fraction :: setDenominator(int a){
    if (a==0){
        throw invalid_argument("Arithmetic exception");
        
    }
    denominator_= a;
    reduct();
}

/*Reduction to all types of legal fractions using the GCD Eucldian algorithm.
a negative fraction is updated to be as a form of -a/b if given as a/-b
*/
void Fraction::reduct() {
    if (denominator_ < 0) {
        numerator_ *= -1;
        denominator_ *= -1;
    }
    
    if (numerator_ == denominator_) {
        numerator_ = 1;
        denominator_ = 1;
        return;
    }
    
    if (numerator_ == 0) {
        if (denominator_ < 0)
            denominator_ *= -1;
        return;
    }
    
    if (denominator_ == 1 || numerator_ == 1) {
        return;
    }
    
    int a = abs(numerator_);
    int b = abs(denominator_);
    
    // Calculate the GCD using the Euclidean algorithm
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a;
    
    numerator_ /= gcd;
    denominator_ /= gcd;
}

/*Multiplication between two fractions.
throws overflow exception in cases that result exceeds the maximum/minimum integer type
returns the result*/
Fraction Fraction:: operator*(const Fraction& fr1) const{
    Fraction otro = fr1;
    long long numerator = static_cast<long long>(numerator_) * otro.numerator_;
    long long denominator = static_cast<long long>(denominator_) * otro.denominator_;
    if (numerator > numeric_limits<int>::max() || numerator < numeric_limits<int>::min() ||
        denominator > numeric_limits<int>::max() || denominator < numeric_limits<int>::min()) {
        throw overflow_error("Overflow occurred during fraction multiplication");
    }
    Fraction res(numerator, denominator);
    return res;
}

/*Division between two fractions.
throws exception if the other numerator equals to zero or if there is an overflow.
returns the result*/
Fraction Fraction::operator/(const Fraction& fr1) const {
    if (fr1.numerator_ == 0) {
        throw runtime_error("Division by zero");
    }
    Fraction otro = fr1;
    long long numerator = static_cast<long long>(numerator_) * otro.denominator_;
    long long denominator = static_cast<long long>(denominator_) * otro.numerator_;

    if (numerator > numeric_limits<int>::max() || numerator < numeric_limits<int>::min() ||
        denominator > numeric_limits<int>::max() || denominator < numeric_limits<int>::min()) {
        throw overflow_error("Overflow occurred during fraction division");
    }
    Fraction res(numerator, denominator);
    return res;
}

/*Addition between two fractions. 
throws exception in case of overflow.
returns the result*/
Fraction Fraction::operator+(const Fraction& fr1) const {
    Fraction otro = fr1;
    long long numerator = static_cast<long long>(numerator_) * otro.denominator_ +
                         static_cast<long long>(otro.numerator_) * denominator_;
    long long denominator = static_cast<long long>(denominator_) * otro.denominator_;

    if (numerator > numeric_limits<int>::max() || numerator < numeric_limits<int>::min() ||
        denominator > numeric_limits<int>::max() || denominator < numeric_limits<int>::min()) {
        throw overflow_error("Overflow occurred during fraction addition");
    }
    Fraction res(numerator, denominator);
    return res;
}

/*Substraction between two fractions.
throws exception in case of an overflow.
return the result*/
Fraction Fraction::operator-(const Fraction& fr1) const {
    Fraction otro = fr1;
    long long numerator = static_cast<long long>(numerator_) * otro.denominator_ -
                         static_cast<long long>(otro.numerator_) * denominator_;
    long long denominator = static_cast<long long>(denominator_) * otro.denominator_;

    if (numerator > numeric_limits<int>::max() || numerator < numeric_limits<int>::min() ||
        denominator > numeric_limits<int>::max() || denominator < numeric_limits<int>::min()) {
        throw overflow_error("Overflow occurred during fraction subtraction");
    }
    Fraction res(numerator, denominator);
    return res;
}
/*Receives two arguments- ostream pointer and fraction to print.
cast to a form of "a/b".
return the os stream back to user.*/
ostream& ariel::operator<<(ostream& os1, const Fraction& fr1){
    return os1 << fr1.numerator_ << "/" << fr1.denominator_;
}
/*Casting a float type to a fraction. 
accuracy of up to 3 points behind the decimal point.
returns a reducted fraction*/
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
/*Division by float.
might throw an arithmetic exception with a zero argument.*/
Fraction Fraction:: operator/(const float& flo) const{
    Fraction casti(flo);
    if (casti.numerator_ == 0){
        throw runtime_error("Division by zero");
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
/*Equality check with another fraction.
considered equal fraction if and only if their reducted fractions are equal.*/
bool Fraction:: operator==(const Fraction& fr1) const{
    if (numerator_==fr1.numerator_*(-1)&& denominator_ == fr1.denominator_*(-1))
        return true;
    if (numerator_==fr1.numerator_ && denominator_== fr1.denominator_)
        return true;
    if (numerator_ == 0 && fr1.numerator_ == 0)
        return true;
    Fraction tmp = fr1;
    tmp.reduct(); 
    if (tmp.numerator_ == numerator_ && tmp.denominator_==denominator_)
        return true;
    return false;
}

bool Fraction :: operator>(const Fraction& fr1)const {
    bool neg = false;
    Fraction tmp1 = *this;
    Fraction tmp2 = fr1;
    tmp1.reduct();
    tmp2.reduct();
    if (tmp1 == tmp2)
        return false;
    if (tmp1.numerator_<=0 && tmp2.numerator_>0)
        return false;
    if (tmp1.numerator_>0 && tmp2.numerator_<=0)
        return true;
    if (tmp1.numerator_<0 && tmp2.numerator_<0){
        neg = true;
        tmp1 = tmp1*(-1);
        tmp2 = tmp2*(-1);
    }
    if (tmp1.denominator_ == tmp2.denominator_){
        if (tmp1.numerator_<tmp2.numerator_){
            return (neg==true ? true : false);
        }
        return (neg==true ? false : true);
    }
    if (tmp1.denominator_>tmp2.denominator_ && tmp1.numerator_<tmp2.numerator_){
        return (neg==true ? true : false);
    }
    if (tmp1.denominator_<tmp2.denominator_ && tmp1.numerator_>tmp2.numerator_){
        return (neg==true ? false : true);
    }
    int nume1 = tmp1.numerator_*tmp2.denominator_;
    int nume2 = tmp2.numerator_*tmp1.denominator_;

    if (nume2 > nume1){
        return (neg==true ? true : false);
    }
    return (neg==true ? false : true);
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
        throw runtime_error("Division by zero");
    }
    if (flo == 0){
        return Fraction(flo);
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
/*Input stream into a fraction. 
only takes a valid input to be 2 integers seperated by either '/',' '(whitespace), ','
throws exception if not valid.
after finish reading one fraction from input stream returns the stream back to user*/
istream& ariel :: operator>> (istream& in1,Fraction& fr1){
    int nume, denom;
    streampos currentPosition = in1.tellg();
    string input;
    string num = "";
    string deno = "";
    getline(in1, input);
    bool delimiter = false;

    if ((input.find(" ") == input.npos) && (input.find("/") == input.npos) && (input.find(",") == input.npos)) {
        throw runtime_error("Invalid input");
        
    }
    if (input.find(".") != input.npos){
        throw runtime_error("Invalid input");
        
    }

    for (char c : input) {
        if (delimiter == false) {
            if (isdigit(c) || c == '-') {
                num += c;
            }
            else {
                if (c != '.' && c != ' ' && c != '/' && c != ',') {
                    throw runtime_error("Cannot create a fraction with undefined chars");
                    
                }

                delimiter = true;
            }
        }
        else {
            if (isdigit(c) || c == '-') {
                deno += c;
            }
            else {
                if (c == '.' || c == ' ' || c == '/' || c == ',') {
                    int sizeofin = (num.size() + deno.size()+2);
                    in1.seekg(currentPosition + static_cast<streampos>(sizeofin));
                    nume = stoi(num);
                    denom = stoi(deno);
                    fr1.numerator_ = nume;
                    fr1.denominator_ = denom;
                    if (fr1.denominator_<0){
                        fr1.denominator_= fr1.denominator_*(-1);
                        fr1.numerator_= fr1.numerator_*(-1);}
                    return in1;
                }
                else {
                    throw invalid_argument("Cannot create a fraction with undefined chars");
                    
                }
            }
        }
    }
    nume = stoi(num);
    denom = stoi(deno);
    if (denom == 0){
        throw runtime_error("Cannot create a fraction with a zero denominator");
        
    }

    fr1.numerator_ = nume;
    fr1.denominator_ = denom;
    if (fr1.denominator_<0){
        fr1.denominator_= fr1.denominator_*(-1);
        fr1.numerator_= fr1.numerator_*(-1);
    }
    return in1;
}
