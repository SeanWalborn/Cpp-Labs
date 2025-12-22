/*
    program that collects integers from user input and stores them in a linked list in ascending order and displays the linked list to the user
    runs until -1 is entered to stop the program. 
*/

#include <iomanip>
#include <iostream>

using namespace std;

// struct declaration
struct Node{
    int data;
    struct Node* link;
};

// function declaration
void addFront(Node*&, int); // adds a Node to the beginning of linked list
void addEnd(Node*, int); // adds a Node to the end of a linked list
void addMiddle(Node*, int, int); // adds a Node to the middle of a linked list at a specific position
void sort (Node*&, int); // places user input in correct position in linked list
    int findIndex(Node*, int); // finds the location the input should be placed for sorting purposes
void printLinkedList(Node*); // prints the linked list 
void deleteLinkedList(Node*&);

int main(){
    // variables
    bool run = true;
    Node* head = nullptr;

    // loop that runs unitl -1 is entered
    while(true){
        int input = 0;   

        // collecting user input
        cout << "Enter integers (-1 to stop): ";
        cin >> input;     

        // checks if program continues to run
        if (input == -1){
            cout << "Final sorted linked list: "; 
            printLinkedList(head);
            break;
        }

        // places node in correct position
        sort(head, input);
        
        // prints node
        printLinkedList(head);
    }

    // deletes list
    deleteLinkedList(head);
}

// function definition
// places user input in correct position in linked list
void sort (Node*& n, int a){
    // variable to store where the input should be placed in the order
    int position = 0;

    // sets up node if first number enters
    if (n == nullptr){
        Node* temp = new Node;
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
void addFront(Node*& n, int a){
    Node* temp = new Node;
    temp -> data = a;
    temp-> link = n;
    n = temp;
    

}

// adds the node to the end of the linked list
void addEnd(Node* n, int input){
    Node* temp = new Node;
    temp -> data = input;
    temp-> link = nullptr;

    while(n->link != nullptr){
        n = n->link;
    }

    n->link = temp;
    
}

// adds the node at a specifc spot in the sequence 
void addMiddle(Node* n,  int input, int position){
    Node* temp = new Node;
    temp -> data = input;
    temp-> link = nullptr; 

    for (int i = 0; i < position -1; i++){
        n = n->link;
    }

    temp->link = n->link;
    n->link = temp;
    
}

// finds the location the input should be placed for sorting purposes
int findIndex(Node* h, int input){
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
void printLinkedList(Node* h){
    bool firstPrint = true;

    // loops through linked list
    while (h != nullptr){
        // prints first node for formating
        if (firstPrint){
            cout << h->data;
            h = h->link;
            firstPrint = false;
        }else{
            cout <<  " -> " << h->data;
            h = h->link;
        }
    }

    cout << endl;
}

// deletes linked list
void deleteLinkedList(Node*& h){

    while(h != nullptr){
        Node* temp = h;
        h = h -> link;
        delete temp;
    }

}
