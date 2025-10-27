// Implementation of Complex class

#include "complex.h"
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

// operators
Complex Complex::add(const Complex c1){
    real = real + c1.real;
    imaginary = imaginary + c1.imaginary;

    return Complex(real, imaginary);
    
}
Complex Complex::subtract(const Complex c1){
    real = real - c1.real;
    imaginary = imaginary - c1.imaginary;

    return Complex(real - c1.real, imaginary - c1.imaginary);

}
Complex Complex::multiply(const Complex c1){
    // temp var to hold varaibles
    double r1 = real;

    real = (real*c1.real)-(imaginary*c1.imaginary);
    imaginary = (r1*c1.imaginary)+(imaginary*c1.real);
    
    return Complex(real, imaginary);
}
void Complex::print(){
    cout << real << " + " << imaginary << "i"<< endl;
}