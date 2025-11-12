/* 
    Lab: 18 Problem 02 
    Name: Sean Walborn 
    ID: 10763229
    Submission Date: 11/09/25
*/

/*
    - Program that collects integers from the user one by one and adds them into a linked list in the order they are entered
    - The program stops collecting integers when the user enters -1 
    - The linked list is printed out in order of user input.
    - user is prompted to enter an index and the interger stored in that node is displayed
    - handles out of ranges cases from user
    - Recursion is used to find the node that the user entered. base code is taken from problem 1 in lab 18

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
int findNode(Node*&, int, int); // Finds the node the user entered
void deleteLinkedList(Node*&); // deletes the linked list

int main(){
    // variables
    bool run = true;
    bool first = true;
    int nodeIndex = 0;
    int nodeValue = 0;
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
            cout << "Enter k: ";
            cin >> nodeIndex;
            nodeValue = findNode(head, nodeIndex, 1);
            // handle out of range input
            if(nodeValue == -1){
                cout << nodeIndex << " is out of range";
            }else{
                cout << "The " << nodeIndex << "th node is " << nodeValue;
            }
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

// returns the int stored in the node that the user entered
int findNode (Node*& head, int index, int count){
    // handles out of range input
    if (index < 1 || head == nullptr){
        return -1;
    }
    
    // base case
    if (index == count){
        return head->data; 
    } 
    else{
        return findNode(head->link, index, count +1 );
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

