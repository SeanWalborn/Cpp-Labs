
/*
    Program that creates two sorted linked lists and merges them, it is assumed that there are no duplicate numbers
    all memory is freed when the program ends. code is manipulated from problem 1. 
    the merged linked list does not create a new linked list but instead adjusts the pointers
*/

#include <iostream>

using namespace std;

// declaring and defining structures
struct node{
    int data;
    node* link;
};

// declaring helper functions
node* createSortedList(int n); // creates a sorted linked list that is n integers long
void mergeTwoLists(node*&, node*&); // merges two sorted linked lists into one sorted linked list
void freeList(node*); // deletes linked list from the heap
void sort (node*&, node *&); // places user input in correct position in linked list
    int findIndex(node*, int); // finds the location the input should be placed for sorting purposes
    void addFront(node*&, node*&); // adds a Node to the beginning of linked list
    void addEnd(node*, node*&); // adds a Node to the end of a linked list
    void addMiddle(node*, node*, int); // adds a Node to the middle of a linked list at a specific position
void printLinkedList(node*); // prints the linked list 

int main() {
    node* head1 = nullptr;
    node* head2 = nullptr;
    int n;
    cout << "Enter number of data for list 1 :";
    cin >> n;
    head1 = createSortedList(n);
    cout << "Enter number of data for list 2 :";
    cin >> n;
    head2 = createSortedList(n);
    mergeTwoLists(head1, head2);
    freeList(head1);
    return 0;
}

// Defining Helper Functions:
// creates a sorted linked list that is n integers long
node* createSortedList(int n){
    node* head = nullptr;
    node* ptr = nullptr;
    
    for(int i = 1; i <= n; i++){
        ptr = new node;
        ptr->link = nullptr;

        // collecting linked list
        cout << "enter number " << i << " : " ;
        cin >> ptr->data;
        
        // sorting linked list
        sort(head, ptr);

        //printing linke list
        cout << "Linked list : ";    
        printLinkedList(head);
    }

    
    return head;
} 


// merges two sorted linked lists into one sorted linked list
void mergeTwoLists(node*& h1, node*& h2){
    while(h2 != nullptr){
        node* temp = h2->link;
        h2->link = nullptr;
        sort(h1, h2);
        h2 = temp;
    }

    // printing merged linked list
    cout << "< Merged linked list >" << endl;
    printLinkedList(h1);
}

// deletes linked list from the heap
void freeList(node* n){
    node* temp = nullptr;

    while(n != nullptr){
        temp = n;
        n = n->link;
        delete temp;
    }
}

// places user input in correct position in linked list
void sort (node*& n, node*& p){
    // variable to store where the input should be placed in the order
    int position = 0;

    // sets up node if first number enters
    if (n == nullptr){ 
        n = p;
    }else {
        position = findIndex(n, p->data);
        // add new input in correct spot
        if (position == 0){
            addFront(n, p);
        }else if (position == -1){
            addEnd(n, p);
        }else{
            addMiddle(n, p, position);
        }
    }

    p = nullptr;
        
}

// adds the node to the front of the linked list
void addFront(node*& n, node *& p){
    p->link = n;
    n = p;
}

// adds the node to the end of the linked list
void addEnd(node* n, node*& p){
    while(n->link != NULL){
        n = n->link;
    }
    n->link = p;  
}

// adds the node at a specifc spot in the sequence 
void addMiddle(node* n,  node* p, int position){
    
    for (int i = 0; i < position -1; i++){
        n = n->link;
    }
    p->link = n->link;
    n->link = p;
    
}

// finds the location the input should be placed for sorting purposes
int findIndex(node* h, int input){
    // local variables
    int count = 0;
    
    // loop that increases count after checking that the input is larger than  data at current node
    while (h != nullptr && h->data < input){
        h =  h->link;
        count++;
    }

    if (h == nullptr){
        count = -1;
    }
    
    return count;
} 

// prints the linked list 
void printLinkedList(node* h){
    bool firstPrint = true;

    // loops through linked list
    while (h){
        // prints first node for formating
        if (firstPrint){
            cout << h->data;
            h = h->link;
            firstPrint = false;
        }else{
            cout <<  "->" << h->data;
            h = h->link;
        }

    }

    cout << "->NULL" << endl;

}
