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
void calcLength(Node* head);
void findInt(Node* head, int);

int main(){
    // variables:
    int input = 0; // used to control loop
    Node* head = nullptr;
    Node* ptr = nullptr;
    bool setHead = true; // use to control setting the head on the first loop
    int search = 0;


    while (true){
        // collecting user input
        cout << "Enter data(enter -1 to stop): ";
        cin >> input;

        // check if program runs - performs search length before ending program
        if (input == -1){
            calcLength(head);

            cout << endl << "Enter data to search for: ";
            cin >> search;
            findInt(head, search);

            break;
        }
        
        // setting head with first node and ptr after first loop
        if (setHead){
            head = new Node;
            head->data = input;
            head->link = NULL;
            setHead = false;
        }
        else{
            ptr = new Node;
            ptr->data = input;
            ptr->link = head;
            head = ptr;    
        }   

        // printing out list
        printList(head);

    }

    deleteList(head);
}

// helper functions defined
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

void calcLength(Node* head){
    int count = 0;
    for (Node* current = head; current; current = current->link){
        count ++;
    }

    cout << "the length of the list: " << count << endl << endl; 

}
void findInt(Node* head, int a){
    int found = 0;
    int count = 0;

    for (Node* current = head; current; current = current->link){
        count++;

        if (current->data == a){
            found = 1;
            break;
        }
    }

    if (found == 1){
        cout << a << " is at " << count << " in the list"; 
    }else{
        cout << a << " not exist in the list";
    }

}
