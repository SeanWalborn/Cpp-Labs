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
        
        // operators
        Complex add(const Complex);
        Complex subtract(const Complex);
        Complex multiply(const Complex);
        void print();

    private:
        double real;
        double imaginary;
};