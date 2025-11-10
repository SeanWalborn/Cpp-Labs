#ifndef polynomialList_h 
#define polynomialList_h


#include "node.cpp"
#include "term.cpp"

using namespace std;

class polynomialList{
    public:
        // constructors / destructor / copy constructor
        polynomialList();
        polynomialList(node* n);
        polynomialList(const polynomialList& p);
        ~polynomialList();

        
        // setters - adds new node to the front of the node
        void insertFront(node* n);
        void insertRear(node* n);
        
        // getters - removes node from the front of the list
        void removeFront();

        // operators
        polynomialList& operator=(const polynomialList& rightSide);

        // friends
        friend polynomialList operator+(polynomialList&, polynomialList& );
        friend ostream& operator<<(ostream& os, const polynomialList& );
        
    private:
        node* head = nullptr;
};

#endif