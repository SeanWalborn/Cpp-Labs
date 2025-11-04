#include <iostream>

using namespace std;

class term {
    public:
        // constructors 
        term();
        term(int coef, int degree);
      
        // setters
        void setDegree(int d);
        void setCoef(int c);

        // getters
        int getDegree() const;
        int getCoef() const;

    private:
        int coef;
        int degree;
};