/* 
Lab: 16 Problem 01 
Name: Sean Walborn 
ID: 10763229
Submission Date: 11/01/25
*/

/*
    Program that is provided two numbers in an array form. each index in the array represents a place value tens, hundred etc. with index 0 being the largest value, index [0] is never 0. the program creates a linked list with each array and then sums the two numbers. The two numbers are presented to the user as well as the sum. In order to sum the numbers the linked lists are reversed so that the place values can be added to their mathcing place value. Memory is freed at the end
*/

#include <iostream>
using namespace std;

// defining structures
struct node {
    int digit;
    node* next;
};

// declaring helper functions
void createLinkedList(node*&, int[], int); // creates linked list from array
void printLinkedList(node*); // prints a linked list
void sumLinkedList(node*, node*, node*&); // sums two linked lists togehter in a new linked list
void reverseLinkedList(node*&); // reverses a linked list
void deleteLinkedList(node*); // deletes linked list

int main()
{
    // variables used
    int A[] = { 9, 9, 8, 6, 5, 7, 1, 0, 0, 3, 5, 5, 0, 7 }; //provided
    int B[] = { 7, 8, 9, 1, 2, 3, 0, 0, 5, 9 }; // provided
    node* list1 = nullptr;
    node* list2 = nullptr;
    node* list3 = nullptr;
    int aLength = sizeof(A)/sizeof(A[0]);
    int bLength = sizeof(B)/sizeof(B[0]);

    // Create two linked lists from A and B.
    createLinkedList(list1, A, aLength);
    createLinkedList(list2, B, bLength);
    
     // printing linked list
    cout << "A : ";
    printLinkedList(list1);
    cout << "B : ";
    printLinkedList(list2);

    // sums the two linked lists and creates a new one to store the data
    sumLinkedList(list1, list2, list3);

     // printing sum
    cout << "S : ";
    printLinkedList(list3);

    // recovering memory
    deleteLinkedList(list1);
    deleteLinkedList(list2);
    deleteLinkedList(list3);
}

// defining helper funcitions
// creates linked list from array
void createLinkedList(node*& n, int a[], int l){
    node* temp = nullptr;
    node* ptr = nullptr;

    // converting the array into a linked list
    for (int i = 0; i < l; i++ ){
        temp = new node;
        temp->digit = a[i];
        temp->next = nullptr;

        if (i == 0 ){
            n = ptr = temp;
        }else{
            while(ptr->next != nullptr){
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
}

// prints a linked list
void printLinkedList(node* h){
    // loops through linked list
    while (h){
        cout << h->digit;
        h = h->next;
    }

    cout << endl;
}

// sums the first two linked lists togehter into the third linked list
void sumLinkedList(node* a, node* b, node*& c){
    reverseLinkedList(a);
    reverseLinkedList(b);
    bool first = true;
    int remainder = 0;

    // adding the two nodes together while both have vaules
    while (a != NULL && b != NULL){
        node* temp = new node;
        temp->next = nullptr;
        temp->digit = a->digit + b->digit + remainder;
    
        // resetting remainder
        remainder = 0;

        // advancing to the next digit
        a = a->next;
        b = b->next;

        // checking if theres a remainder and handling it
        if (temp->digit > 9){
            remainder = 1;
            temp->digit = temp->digit - 10;
        }
        
        // checking if first iteration to setup new linked list correctly
        if(first){
            first = false;
            c = temp; 
        }else{
            temp->next = c;
            c = temp;
        }

    }

    
    // adding in the remaining numbers into the correct place depending which number is larger
    if ( a == nullptr){
        while(b!= nullptr){
            node* temp = new node;
            temp->next = nullptr;
            temp->digit =  b->digit + remainder;
        
            // resetting remainder
            remainder = 0;

            // advancing to the next digit
            b = b->next;

            // adding the node to the linked list
            temp->next = c;
            c = temp;
        }
    }else {
        while(a != nullptr){
            node* temp = new node;
            temp->next = nullptr;
            temp->digit =  a->digit + remainder;
        
            // resetting remainder
            remainder = 0;

            // advancing to the next digit
            a = a->next;

            // adding the node to the linked list
            temp->next = c;
            c = temp;
        }
    }
}

// reverses a linked list
void reverseLinkedList(node*& h){
    node* prev = h;
    node* next = nullptr;
    h = h->next;
    prev->next = nullptr;

    while (h->next != nullptr){
        next = h->next;
        h->next = prev;
        prev = h;
        h = next;
    }

    h->next = prev;
} 

// deletes linked list
void deleteLinkedList(node* n){
    node* temp = nullptr;

    while(n != nullptr){
        temp = n;
        n = n->next;
        delete temp;
    }
}
