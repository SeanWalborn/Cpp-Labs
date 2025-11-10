
       #include "node.h"
       #include "term.h"

       using namespace std;

       // constructors
        node::node(){
            data.setCoef(0);
            data.setDegree(0);
            link = nullptr;
        }

        node::node(term data){
            this->data.setCoef(data.getCoef());
            this->data.setDegree(data.getDegree());
            this->link = nullptr;
        }

        node::node(term data, node* link){
            this->data.setCoef(data.getCoef());
            this->data.setDegree(data.getDegree());
            this->link = link;
        }


