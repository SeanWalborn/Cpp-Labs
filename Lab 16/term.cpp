 #include <iostream>
 #include "term.h"

 using namespace std;
 
 // constructors 
term::term(){
    degree = 0;
    coef = 0;
}
term::term(int c, int d){
    degree = d;
    coef = c;
}

// setters
void term::setDegree(int d) {
    degree = d;
}
void term::setCoef(int c){ 
   coef = c;
}

// getters
int term::getDegree() const{
    return degree;
}
int term::getCoef() const{
    return coef;
}

