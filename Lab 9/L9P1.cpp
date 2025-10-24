/* 
Lab: 09 Problem 01 
Name: Sean Walborn 
ID: 10763229
Submission Date: 09/25/25
*/

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
    
    Rational add(const Rational& );
    Rational subtract(const Rational&);
    Rational multiply(const Rational&);
    Rational divide(const Rational&);
    void print();

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

// public class functions defined
Rational Rational::add(const Rational& r1){
    int num = (numerator * r1.denominator) + (denominator * r1.numerator);
    int denom = denominator * r1.denominator;

    // creating new rational number and reducing it
    Rational r2(num, denom);
    r2.reduce();

    return r2;
}
Rational Rational::subtract(const Rational& r1){
    int num = (numerator * r1.denominator)-(denominator * r1.numerator);
    int denom = denominator * r1.denominator;
   
    // creating new rational number and reducing it
    Rational r2(num, denom);
    r2.reduce();

    return r2;
}
Rational Rational::multiply(const Rational& r1){
    int num = numerator * r1.numerator;
    int denom = denominator * r1.denominator;
    
    // creating new rational number and reducing it
    Rational r2(num, denom);
    r2.reduce();

    return r2;
}
Rational Rational::divide(const Rational& r1){
    int num = numerator * r1.denominator;
    int denom = denominator * r1.numerator;

   // creating new rational number and reducing it
    Rational r2(num, denom);
    r2.reduce();

    return r2;
}
void Rational::print(){
    cout<< numerator << " / " << denominator << endl;
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

// main provided in class for testing

// int main()
// {
//     int numerator, denominator;
//     cout << "Enter rational for r1 : ";
//     cin >> numerator >> denominator;
//     Rational r1(numerator, denominator);
//     cout << "Enter rational for r2 : ";
//     cin >> numerator >> denominator;
//     Rational r2(numerator, denominator);
//     Rational r3 = r1.add(r2);
//     Rational r4 = r1.subtract(r2);
//     Rational r5 = r1.multiply(r2);
//     Rational r6 = r1.divide(r2);
//     cout << "r1 + r2 = "; r3.print();
//     cout << "r1 - r2 = "; r4.print();
//     cout << "r1 * r2 = "; r5.print();
//     cout << "r1 / r2 = "; r6.print();
//     return 0;
// }