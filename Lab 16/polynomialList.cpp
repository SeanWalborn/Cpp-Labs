#include "node.cpp"
#include "term.cpp"
#include "polynomialList.h"

using namespace std;

// constructors/ copy constructors/ destructors 
polynomialList::polynomialList(){
    head = nullptr;
};

polynomialList::polynomialList(node* n){
    head->link = nullptr;
    head = n;
};

polynomialList::polynomialList(const polynomialList& p){
    head = p.head;
};

polynomialList::~polynomialList(){

};

void polynomialList::insertFront(node* n){
    n->link = head;
    head = n;
};

node* polynomialList::removeFront(){
    node* temp = head;
    head = head->link;
    return temp;
};

polynomialList operator+(polynomialList& a, polynomialList& b){

};

ostream& operator<<(ostream& os, const polynomialList& p){
    node* temp = p.head;
    bool first = true;

    while (temp != nullptr){
        // handles sign for first case
        if(first){
            cout << temp->data.getCoef() << "x^" << temp->data.getDegree() << " ";
            first = false;
        }else{
            // handles formating for negative coefficients
            if (temp->data.getCoef()< 0){
                cout << "- "<< temp->data.getCoef()*-1 << "x^" << temp->data.getDegree() << " ";
            }else{
                cout << "+ " <<temp->data.getCoef() << "x^" << temp->data.getDegree();
            }
        }
        
        // moves temp to the next term in the polynomial
        temp = temp->link;
    }
};




int main (){
    polynomialList poly1;
    for (int i = 0; i < 5; i++){
        term t;
        t.setCoef(i);
        t.setDegree(i);
        node* temp(t, nullptr);
        
       

        poly1.insertFront(temp);
    }

    cout << poly1;
}
