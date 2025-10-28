// Implementation of Complex class

#include "complex2.h"
#include <iostream>
#include <iomanip>

using namespace std;

// constructors
Complex::Complex() : real(0), imaginary(0) {}
Complex::Complex(double r, double i) : real(r), imaginary(i) {}

// setters
void Complex::setReal(double r){
    real = r;
}
void Complex::setImaginary(double i){
    imaginary = i;
}

// getters
double Complex::getReal(){
    return real;
}
double Complex::getImaginary(){
    return imaginary;
}

// friend operators
Complex operator+(const Complex& c1, const Complex& c2){
    double real = c1.real + c2.real;
    double imaginary = c1.imaginary + c2.imaginary;

    return Complex(real, imaginary);
    
}
Complex operator-(const Complex& c1, const Complex& c2){
    double real = c1.real - c2.real;
    double imaginary = c1.imaginary - c2.imaginary;

    return Complex(c1.real - c2.real, c1.imaginary - c2.imaginary);

}
Complex operator*(const Complex& c1, const Complex& c2){
        
    double real = (c1.real*c2.real)-(c1.imaginary*c2.imaginary);
    double imaginary = (c1.real*c2.imaginary)+(c1.imaginary*c2.real);
    
    return Complex(real, imaginary);
}
ostream& operator<<(ostream& os, const Complex& c1){
    os << c1.real << " + " << c1.imaginary << "i";
    return os;
}
istream& operator>>(istream& ins, Complex& c1){
    ins >> c1.real >> c1.imaginary;
    return ins;
}

