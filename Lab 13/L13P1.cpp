#include <iostream>

using namespace std;

// struct to create a node
struct Node{
    int data;
    Node* link;
};

// helper functions
void printList(Node* head);
void deleteList(Node* head);

int main(){
    // variables:
    int input = 0; // used to control loop
    Node* head = nullptr;
    Node* ptr = nullptr;
    Node* previous = nullptr; 
    bool setHead = true; // use to control setting the head on the first loop


    while (true){
        // collecting user input
        cout << "Enter data(enter -1 to stop): ";
        cin >> input;

        // check if program runs
        if (input == -1){
            break;
        }
        
        // builds new node and updates with input
        ptr = new Node;
        ptr->data = input;
        ptr->link = NULL;

        // setting head for first run updates previous on following loops
        if (setHead){
            head = ptr;
            previous = head;
            setHead = false;
        }else{
            previous->link = ptr;
            previous = ptr;
        }
             
        // printing out list
        printList(head);

    }

    deleteList(head);
}

void printList(Node* head){
    // local variables
    bool first = true;
    cout << "Data in the list: [ " ;

    for (Node* current = head; current; current = current->link){
        if (first){
            cout << current->data;
            first = false;
        }else{
            cout << " -> " << current->data; 
        }
         
    }

    cout << " ]" << endl << endl;
}

void deleteList(Node* head){
    for (Node* current = head; current;){
        Node* tempNode = current;
        current = current->link;
        delete tempNode;
    }

}
