#include <iostream>

using namespace std;

class Complex
{
    public:
        // constructors
        Complex();
        Complex(double, double);

        // setters
        void setReal(double); 
        void setImaginary(double);

        // getters
        double getReal();
        double getImaginary();
        
        // friend operators
        friend Complex operator+(const Complex& a, const Complex& b);
        friend Complex operator-(const Complex& a, const Complex& b);
        friend Complex operator*(const Complex& a, const Complex& b);
        friend ostream& operator<<(ostream&, const Complex&);
        friend istream& operator>>(istream&, Complex&);
        

        

    private:
        double real;
        double imaginary;
};