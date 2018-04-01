#include <iostream>
#include "class_container.hpp"
  
using namespace std;

typedef struct tree_element {
    int value;          // Element value
    struct tree_element* left;  // Pointer to left subtree
    struct tree_element* right; // Pointer to right subtree
    struct tree_element* parent; //Pointer to parent
} tree_element;


class SimpleTree: public Container
{
public:
    SimpleTree();
    ~SimpleTree();
    void insert(int value);
    bool exists(int value);
    void remove(int value);
    void print();

protected:
    void deletion(tree_element* element);
    tree_element* insert_pre(tree_element* elem, tree_element* root);
    void print_element(tree_element* i);
    tree_element* create(int i);
    tree_element* find(int value);
    tree_element* find1(int value, tree_element* root);
    tree_element* root;
    tree_element* search(tree_element* elem);
    tree_element* search1(tree_element* elem);
};


