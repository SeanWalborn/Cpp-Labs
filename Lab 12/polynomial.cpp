 #include <iostream>
 #include "polynomial.h"

 using namespace std;
 
 // constructors - destructors
Polynomial::Polynomial(){
    degree = MAX_COUNT;
    coef = new int[MAX_COUNT];
}
Polynomial::Polynomial(int* c, int d){
    degree = d;
    coef = new int[d+1];
    for (int i = 0; i <= d; i++){
        coef[i] = c[i];
    }
}
Polynomial::Polynomial(const Polynomial& p){
    degree = p.degree;
    coef = new int[p.degree + 1];
    for (int i = 0; i <= p.degree; i++){
        coef[i] = p.coef[i];
    }
}
Polynomial::~Polynomial(){
    delete[] coef;
}

// setters
void Polynomial::setDegree(int d) {
    degree = d;
}
void Polynomial::setCoef(int* c, int d) {
    delete [] coef;
    degree = d;
    coef = new int [d +1];

    for (int i = degree; i >= 0; i--){
        coef[i] = c[i];
    }

}

// getters
int Polynomial::getDegree(){
    return degree;
}
int* Polynomial::getCoef(){
    return coef;
}

// operators
Polynomial& Polynomial::operator=(const Polynomial& rightSide){
    delete [] coef;
    degree = rightSide.degree;
    coef = new int [rightSide.degree +1];

    for (int i = degree; i >= 0; i--){
        coef[i] = rightSide.coef[i];
    }

    return *this;

}
Polynomial operator+(const Polynomial& a, const Polynomial& b){
    // finding shortest/longest array to control loop and return object
    int shortest = 0;
    int longest = 0;
    Polynomial tempPoly;

    if (a.degree > b.degree){
        shortest = b.degree;
        longest = a.degree;
        tempPoly = a;
    }else{
        shortest = a.degree;
        longest = b.degree;
        tempPoly = b;
    }

    // setting up array for return polynomial
    int* tempArr = new int [longest +1]{0};

    for (int i = 0; i  <= shortest; i++){
        tempArr[i] = a.coef[i] + b.coef[i];
        
    }

    // adding remianing values
    for (int i = shortest + 1; i <= longest; i++){
        tempArr[i] = -tempPoly.coef[i];
    }

    Polynomial result (tempArr, longest);
    delete[] tempArr;
    return result;
     
}

Polynomial operator-(const Polynomial& a, const Polynomial& b){
    // finding shortest/longest array to control loop and return object
    int shortest = 0;
    int longest = 0;
    Polynomial tempPoly;

    if (a.degree > b.degree){
        shortest = b.degree;
        longest = a.degree;
        tempPoly = a;
    }else{
        shortest = a.degree;
        longest = b.degree;
        tempPoly = b;
    }

    // setting up array for return polynomial
    int* tempArr = new int [longest +1]{0};

    for (int i = 0; i  <= shortest; i++){
        tempArr[i] = a.coef[i] - b.coef[i];
    }

    // adding remianing values
    for (int i = shortest + 1; i <= longest; i++){
        if (a.degree > b.degree){
            tempArr[i] = a.coef[i];
        }else{
            tempArr[i] = - b.coef[i];
        }  
    }

    Polynomial result (tempArr, longest);
    delete[] tempArr;
    return result; 
    
    
}
ostream& operator<<(ostream& os, const Polynomial& p){
    
    for (int i = p.degree; i >= 0; i-- ){
        if (p.coef[i] != 0 && i != 0 ){
            os << p.coef[i] << "x^" << i << " + "; 
        } else if (p.coef[i] != 0){
            os << p.coef[i] << "x^" << i;
        }
    }
    return os;
}