/* 
Lab: 15 Problem 01 
Name: Sean Walborn 
ID: 10763229
Submission Date: 10/26/25
*/

/*
    Program that creates two sorted linked lists and merges them, it is assumed that there are no duplicate numbers
    all memory is freed when the program ends. Main funciton is provided
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
node* mergeTwoLists(node*, node*); // merges two sorted linked lists into one sorted linked list
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
    int n;
    cout << "Enter number of data for list 1 :";
    cin >> n;
    head1 = createSortedList(n);
    cout << "Enter number of data for list 2 :";
    cin >> n;
    head2 = createSortedList(n);
    mhead = mergeTwoLists(head1, head2);
    freeList(head1);
    freeList(head2);
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
node* mergeTwoLists(node* h1, node* h2){
    node* head = nullptr;


    // pushing the first linked list to the new linked list
    while(h1 != nullptr){
        sort(head, h1->data);
        h1 = h1->link;
    }

    while(h2 != nullptr){
        sort(head, h2->data);
        h2 = h2->link;
    }


    // printing merged linked list
    cout << "< Merged linked list >" << endl;
    printLinkedList(head);

    return head;
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