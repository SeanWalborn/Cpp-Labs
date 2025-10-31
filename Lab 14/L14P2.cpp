/* 
Lab: 14 Problem 02 
Name: Sean Walborn 
ID: 10763229
Submission Date: 10/26/25
*/

/*
    program that collects integers from user input and stores them in a linked list and displays the linked list to the user
    runs until -1 is entered to stop the program prints the final linked list and then reveres it a prints the reverse as well. 
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
void reverseLinkedList(Node*&); // reverses the linked list without creating a new one
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
            reverseLinkedList(head);
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

// reverses the linked list without creating a new one
void reverseLinkedList(Node*& head){
    Node* prev = head;
    Node* next = nullptr;
    head = head->link;
    prev->link = nullptr;

    while (head->link != nullptr){
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }

    head->link = prev;

} 

// deletes linked list
void deleteLinkedList(Node*& h){

    while(h != nullptr){
        Node* temp = h;
        h = h -> link;
        delete temp;
    }
}