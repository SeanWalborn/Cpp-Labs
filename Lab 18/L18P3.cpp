/* 
    Lab: 18 Problem 03 
    Name: Sean Walborn 
    ID: 10763229
    Submission Date: 11/09/25
*/

/*
    - program that created two sorted linked list and merges them.
    - the length of each list is collected from the user before prompting the user to enter the integers for the list. the input is sorted as it's entered 
    - it's assumed there are no duplicate numbers 
    - each list is displayed to the user as it is built
    - recursive function merges the two sorted linked lists into a single linked list
    - uses lab 15 problem 1 as the base code
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
node* mergeTwoLists(node*, node*); // merges two sorted linked lists into one sorted linked list using recursion
void freeList(node*); // deletes linked list from the heap
void sort (node*&, int); // places user input in correct position in linked list
    int findIndex(node*, int); // finds the location the input should be placed for sorting purposes
    void addFront(node*&, int); // adds a Node to the beginning of linked list
    void addEnd(node*, int); // adds a Node to the end of a linked list
    void addMiddle(node*, int, int); // adds a Node to the middle of a linked list at a specific position
void printLinkedList(node*); // prints the linked list 

int main() {
    node* head1 = nullptr;
    node* head2 = nullptr;
    node* mhead = nullptr;
    node* end = nullptr;
    int n;
    cout << "Enter number of data for list 1 :";
    cin >> n;
    head1 = createSortedList(n);
    cout << "Enter number of data for list 2 :";
    cin >> n;
    head2 = createSortedList(n);
    mhead = mergeTwoLists(head1, head2);
    cout << "< Merged linked list >" << endl;
    printLinkedList(mhead);
    freeList(mhead);
    return 0;
}

// Defining Helper Functions:
// creates a sorted linked list that is n integers long
node* createSortedList(int n){
    node* head = nullptr;
    
    for(int i = 1; i <= n; i++){
        int input;

        // collecting linked list
        cout << "enter number " << i << " : " ;
        cin >> input;
        
        // sorting linked list
        sort(head, input);

        //printing linke list
        cout << "Linked list : ";    
        printLinkedList(head);
    }

    
    return head;
} 


// merges two sorted linked lists into one sorted linked list
node* mergeTwoLists(node* h1, node* h2 ){
    
    // base cases
    if (h1 == nullptr){
        return h2;  
    }
    if (h2 == nullptr){
        return h1;
    }

    node* temp = nullptr;

    // finds smaller node to add to list
    if (h1->data < h2->data){
        temp = h1;
        temp->link = mergeTwoLists(h1->link, h2);
    }else{
        temp = h2;
        temp->link = mergeTwoLists(h1,h2->link);    
    }

    return temp;
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
void sort (node*& n, int a){
    // variable to store where the input should be placed in the order
    int position = 0;

    // sets up node if first number enters
    if (n == nullptr){
        node* temp = new node;
        temp->data = a;
        temp->link = nullptr; 
        n = temp;
    }else {
        position = findIndex(n, a);
        // add new input in correct spot
        if (position == 0){
            addFront(n, a);
        }else if (position == -1){
            addEnd(n, a);
        }else{
            addMiddle(n, a, position);
        }
    }
        
}

// adds the node to the front of the linked list
void addFront(node*& n, int a){
    node* temp = new node;
    temp -> data = a;
    temp-> link = n;
    n = temp;
    

}

// adds the node to the end of the linked list
void addEnd(node* n, int input){
    node* temp = new node;
    temp -> data = input;
    temp-> link = NULL;

    while(n->link != NULL){
        n = n->link;
    }

    n->link = temp;
    
}

// adds the node at a specifc spot in the sequence 
void addMiddle(node* n,  int input, int position){
    node* temp = new node;
    temp -> data = input;
    temp-> link = nullptr; 

    for (int i = 0; i < position -1; i++){
        n = n->link;
    }

    temp->link = n->link;
    n->link = temp;
    
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