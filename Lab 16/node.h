#include "term.cpp"

using namespace std;

class node{
    public:
        // constructors
        node();
        node(term data, node* link);

        // setters and getter not required since variables are public
        term data;
        node* link;
};