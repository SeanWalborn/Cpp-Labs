
       #include "node.h"
       #include "term.cpp"

       using namespace std;

       // constructors
        node::node(){
            data = term();
            link = nullptr;
        }

        node::node(term data, node* link){
            this->data = data;
            this->link = link;
        }
