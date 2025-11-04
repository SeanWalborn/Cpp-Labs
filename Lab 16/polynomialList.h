#include "Node.cpp"
#include "Polynomial.cpp"

using namespace std;

class LinkedList{
    public: 
        LinkedList();
        ~LinkedList();

        void insert(Polynomial data); // adds a polynomial to the front of the list
        void remove(Polynomial data); // removes the top polynomial
        void printList() const; // prints the linked list

    private:
        Node* head = nullptr;
};