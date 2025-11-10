#include "node.h"
#include "term.h"
#include "polynomialList.h"

using namespace std;

// constructors/ copy constructors/ destructors 
polynomialList::polynomialList(){
    head = nullptr;
    
};

polynomialList::polynomialList(node* n){
    head = n;
    head->link = nullptr;
};

polynomialList::polynomialList(const polynomialList& p){
    // checks if linked list is empty
    if (p.head == nullptr){
        head = nullptr;
        return;
    }

    // makes a copy of the first node
    head = new node(p.head->data);
    node* ptr = head; // tracks new linked list
    node* pTemp = p.head->link; // tracks old linked list

    // loops through and makes new node for list until it reaches the end 
    while(pTemp != nullptr){
        ptr->link = new node(pTemp->data); // links to next node in original
        ptr = ptr->link; // move ptr to next node in new list
        pTemp = pTemp->link;  // moves to next node in orginal list
    }

    // ties off last node
    ptr->link = nullptr;
};

polynomialList::~polynomialList(){
    // loop through to delete each node
    while(head != nullptr){
        node* temp = head;
        head = head->link;
        delete temp;
    }

};

void polynomialList::insertFront(node* n){
    n->link = head;
    head = n;
};

void polynomialList::insertRear(node* n){
    node* temp = head; // to traverse to end of list
    
    // checking if empty
    if (head == nullptr){
        head = n;
    }
    else{
        while(temp->link !=nullptr){
            temp = temp->link;
        }   

        temp->link = n;
    }

    n->link = nullptr;
};

void polynomialList::removeFront(){
    node* temp = head;
    head = head->link;
    delete temp;
   
};

polynomialList& polynomialList::operator=(const polynomialList& rightSide){
    // checking if the sides are equal
    if (this == &rightSide){
        return *this;
    }
    
    // deleting left side list
    while (head != nullptr){
        node* temp = head;
        head = head -> link;
        delete temp;
    }

    // variables used for new list
    bool first = true;
    head = nullptr;
    node* tempRS = rightSide.head;
    node* tempEnd = nullptr;

    // looping through old list and creating deep copy of new list
    while (tempRS != nullptr){
        node* ptr = new node(tempRS->data);
        if(first){
            head = ptr;
            tempEnd = ptr;
            first = false;
        }else{
            tempEnd->link = ptr;
            tempEnd = ptr; 
        }
        tempRS = tempRS->link;

    }

    return *this;
 };

polynomialList operator+(polynomialList& a, polynomialList& b){
    node* aNext = a.head;
    node* bNext = b.head;
    polynomialList Sum;
    
    // loops through both list until the end is reached and decides which list to add from
    while (aNext != nullptr || bNext != nullptr){
                
        if (aNext != nullptr && bNext != nullptr){ // check if a and b have remaining nodes
            if(aNext->data.getDegree() == bNext->data.getDegree()){ // runs if degrees are equal
                term tempT(aNext->data.getCoef()+bNext->data.getCoef(), aNext->data.getDegree()); // creates combined term
                node* tempN = new node(tempT); // creates node to pass
                Sum.insertRear(tempN);
                bNext = bNext->link;
                aNext = aNext->link;
            }
            else if(aNext->data.getDegree() < bNext->data.getDegree()){ // runs if b deg is higher
                Sum.insertRear(new node(bNext->data));
                bNext = bNext->link;

            }else{ // runs if a deg is higher
                Sum.insertRear(new node(aNext->data));
                aNext = aNext->link;
            }
        } else if (aNext == nullptr ){ // only b reamins
            Sum.insertRear(new node(bNext->data));
            bNext = bNext->link;
        } else { // only a remains
            Sum.insertRear(new node(aNext->data));
            aNext = aNext->link;
        }

    }

    return Sum;
    
};

ostream& operator<<(ostream& os, const polynomialList& p){
    node* temp = p.head;
    bool first = true;

    while (temp != nullptr){
        // handles sign for first case
        if(first){
            os << temp->data.getCoef() << "x^" << temp->data.getDegree();
            first = false;
        }else{
            // handles formating for negative coefficients
            if (temp->data.getCoef()< 0){
                os << " - "<< temp->data.getCoef()*-1 << "x^" << temp->data.getDegree();
            }else{
                os << " + " <<temp->data.getCoef() << "x^" << temp->data.getDegree();
            }
        }
        
        // moves temp to the next term in the polynomial
        temp = temp->link;
    }

    return os;
};





