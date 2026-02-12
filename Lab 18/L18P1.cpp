
/*
    - Program that collects integers from the user one by one and adds them into a linked list in the order they are entered
    - The program stops collecting integers when the user enters -1 
    - The linked list is printed out in order of user input and then reveresed order before ending the program.
    - Recursion is used to reverse the linked list. base code is taken from problem 2 in lab 14
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
void printLinkedList(Node*); // prints the linked list 
Node* reverseLinkedList(Node*&, Node*&); // reverses the linked list without creating a new one
void deleteLinkedList(Node*&); // deletes the linked list

int main(){
    // variables
    bool run = true;
    bool first = true;
    Node* head = new Node;
    Node* end = nullptr;
    Node* ptr = nullptr;

    // loop that runs unitl -1 is entered
    while(true){
        int input = 0;   

        // collecting user input
        cout << "Enter integers (-1 to stop): ";
        cin >> input;     

        // checks if program continues to run
        if (input == -1){
            cout << "[Final linked list   ] "; 
            printLinkedList(head);
            Node* prev = head;
            head = reverseLinkedList(head->link, prev);
            cout << "[Reversed linked list] ";
            printLinkedList(head);
            break;
        }

        // adds input to linked list at the end 
        if (first){
            head->data = input;
            head->link = nullptr;
            end = head;
            first = false;
        }else{
            ptr = new Node;
            ptr->data = input;
            ptr->link = nullptr;
            end->link = ptr;
            end = ptr;
        }

        // prints node
        printLinkedList(head);
    }

    // deletes list
    deleteLinkedList(head);
}

// function definition
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

// reverses the linked list without creating a new one using recursion
Node* reverseLinkedList(Node*& head, Node*& prev){
    // base case
    if (head == nullptr){
        return prev; 
    } else{  
        Node* next = head->link;
        head->link = prev;
        return reverseLinkedList(next,head);
    }
} 

// deletes linked list
void deleteLinkedList(Node*& h){

    while(h != nullptr){
        Node* temp = h;
        h = h -> link;
        delete temp;
    }

}
