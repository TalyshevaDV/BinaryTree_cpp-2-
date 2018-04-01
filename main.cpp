#include <iostream>
#include "class_SimpleTree.hpp"
#include "class_container.hpp"
  
using namespace std;

int main()
{
    Container* c = new SimpleTree();

    for(int i = 1; i < 10; i++)
        {
            // printf("1\n");
            c->insert(i*i);
            // printf("1\n");
        }


    cout << "List after creation:" << endl;
    // printf("6\n");
    c->print();

    if(c->exists(25))
        cout << "Search for value 25: found" << endl;

    if(c->exists(111))
        cout << "Search for value 111: not found" << endl;
    
    c->remove(25);
   
    

    cout << "List after deletion of the element:" << endl;
    c->print();

    delete c;
    return 0;
}