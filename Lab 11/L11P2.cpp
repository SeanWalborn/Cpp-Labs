


#include <iomanip>
#include <iostream>

using namespace std;

class Rational
{
    public:
    Rational();
    Rational(int, int);

    // Setters
    void setDenominator(int d);
    void setNumerator(int n);

    // getters
    int getDenominator();
    int getNumerator();
    
    friend Rational operator+(const Rational& a, const Rational& b );
    friend Rational operator-(const Rational& a, const Rational& b);
    friend Rational operator*(const Rational& a, const Rational& b);
    friend Rational operator/(const Rational& a, const Rational& b);
    friend istream& operator>>(istream&, Rational&);
    friend ostream& operator<<(ostream&, const Rational&);

    private:
    int numerator;
    int denominator;
    void reduce(); // make 2/4 --> 1/2 (reduce function is used only in the class)
};
// constructors defined
Rational::Rational(){
    numerator = 0;
    denominator = 1;
}
Rational::Rational(int n, int d){
    numerator = n;
    denominator = d;

}

// Setters defined
void Rational::setDenominator(int d){
    denominator = d;
}
void Rational::setNumerator(int n){
    numerator = n;
}

// getters defined
int Rational::getDenominator(){
    return denominator;
}
int Rational::getNumerator(){
    return numerator;
}

// public class friend functions defined
Rational operator+(const Rational& r1, const Rational& r2){
    int num = (r1.numerator * r2.denominator) + (r1.denominator * r2.numerator);
    int denom = r1.denominator * r2.denominator;

    // creating new rational number and reducing it
    Rational r3(num, denom);
    r3.reduce();

    return r3;
}
Rational operator-(const Rational& r1, const Rational& r2){
    int num = (r1.numerator * r2.denominator)-(r1.denominator * r2.numerator);
    int denom = r1.denominator * r2.denominator;
   
    // creating new rational number and reducing it
    Rational r3(num, denom);
    r3.reduce();

    return r3;
}
Rational operator*(const Rational& r1, const Rational& r2){
    int num = r1.numerator * r2.numerator;
    int denom = r1.denominator * r2.denominator;
    
    // creating new rational number and reducing it
    Rational r3(num, denom);
    r3.reduce();

    return r3;
}
Rational operator/(const Rational& r1, const Rational& r2){
    int num = r1.numerator * r2.denominator;
    int denom = r1.denominator * r2.numerator;

   // creating new rational number and reducing it
    Rational r3(num, denom);
    r3.reduce();

    return r3;
}
ostream& operator<<(ostream& os, const Rational& r1){
    os << r1.numerator << " / " << r1.denominator;
    return os;
}
istream& operator>>(istream& ins, Rational& r1){
    char divide;
    ins >> r1.numerator >> divide >>  r1.denominator;
    return ins;
}


// private class functions defined
void Rational::reduce(){
    int GCD = 1;
    bool negNum = false;
    bool negDenom = false;
    
    // checking if numerator or denominator is neg changing to pos for finding GCD
    if (numerator < 0 ){
        negNum = true;
        numerator = -numerator;
    }
    if (denominator < 0 ){
        negDenom = true;
        denominator = -denominator;
    }

    // finding whether largest number is denominator or numerator then finding GCD - handles edges cases
    if (numerator == denominator){
        numerator = 1;
        denominator = 1;

    }else if (numerator == 0){
        denominator = 1; 
    }else if (denominator > numerator){
        for(int i = 1; i <= numerator; i++){
            if(numerator % i == 0 && denominator % i == 0){
                GCD = i;
            }
        }
    }else{
        for(int i = 1;  i <= denominator; i++){
            if(numerator % i == 0 && denominator % i == 0){
                GCD = i;
            }
        }
    }

    // reducing denom and num
    numerator = numerator / GCD;
    denominator = denominator / GCD;

    // returning to neg if only one number is neg
    if (negNum ^ negDenom){
        numerator = -numerator;
    }
   
}


int main()
{
    Rational r1, r2, r3, r4, r5, r6;
    cout << "Enter rational for r1 : ";
    cin >> r1;
    cout << "Enter rational for r2 : ";
    cin >> r2;
  
    r3 = r1 + r2;
    r4 = r1 - r2;
    r5 = r1 * r2;
    r6 = r1 / r2;
    cout << "r1 + r2 = " << r3 << endl;
    cout << "r1 - r2 = " << r4 << endl;
    cout << "r1 * r2 = " << r5 << endl;
    cout << "r1 / r2 = " << r6 << endl;
    

}
