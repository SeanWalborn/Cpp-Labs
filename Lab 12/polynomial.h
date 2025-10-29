#include <iostream>
#define MAX_COUNT 100

using namespace std;

class Polynomial {
    public:
        // constructors - destructors
        Polynomial();
        Polynomial(int* coef, int degree);
        Polynomial(const Polynomial& p);
        ~Polynomial();

        // setters
        void setDegree(int d);
        void setCoef(int* coef, int d);

        // getters
        int getDegree();
        int*getCoef();

        // operators
        Polynomial& operator=(const Polynomial& rightSide);
        friend Polynomial operator+(const Polynomial&, const Polynomial&);
        friend Polynomial operator-(const Polynomial&, const Polynomial&);
        friend ostream& operator<<(ostream& os, const Polynomial& );

    private:
        int* coef;
        int degree;
};