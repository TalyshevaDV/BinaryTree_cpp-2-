#include <iostream>
#include "class_SimpleTree.hpp"
  
using namespace std;

SimpleTree::SimpleTree()
{
    this->root = NULL;
}

SimpleTree::~SimpleTree()
{    
    deletion(this->root);
}

void SimpleTree::deletion(tree_element* element) 
{
    if (element != NULL){
        deletion(element->left);
        deletion(element->right);
        delete(element);
        cout << "Element deleted" << endl;
    }
}

tree_element* SimpleTree::create(int value)
{
    
    tree_element* elem = (tree_element*)malloc(sizeof(tree_element));
    elem->value = value;
    elem->right = NULL;
    elem->left = NULL;
    return elem;
}

void SimpleTree::insert(int value)
{
    tree_element* elem = this->create(value);
       
    if(this->root == NULL)
    {
        this->root = elem;
    }
    insert_pre(elem, this->root);
}

tree_element* SimpleTree::insert_pre(tree_element* elem, tree_element* root) {
    tree_element* cur_root = root;
    if (elem < cur_root && cur_root->left == NULL) {
        cur_root->left = elem;
        elem->parent = cur_root;

    } else if (elem > cur_root && cur_root->right == NULL) {
        cur_root->right = elem;
        elem->parent = cur_root;
    } else if (elem < cur_root && cur_root != NULL) {
        insert_pre(elem, cur_root->left);

    } else if (elem > cur_root && cur_root != NULL) {
        insert_pre(elem, cur_root->right);
    }
    return (cur_root);
}
bool SimpleTree::exists(int value)                 //добавлена проверка value
{
    if (value == 0) {
    return 0;
  } else if (value != 0) {
    tree_element* cur_element = this->find(value);
    return find(value) != NULL;
  }
}

tree_element* SimpleTree::find1(int value, tree_element* root)  //другая последовательность условий на cur_element
{                                                               //сначала проверка на NULL
    tree_element* cur_element = root;
    if (cur_element == NULL) {
        return NULL;
    } else if (cur_element->value == value && cur_element->value != 0) {
        return cur_element;
    
    } else if (cur_element->value < value && cur_element->right != NULL) {         //ситуация, если нужно идти туда, где NULL
        return find1(value, cur_element->right);
    } else if (cur_element->value < value && cur_element->right == NULL) {
        return NULL;
    } else if (cur_element->value > value && cur_element->left != NULL) {
        return find1(value, cur_element->left);
    } else if (cur_element->value > value && cur_element->left == NULL) {
          return NULL;
    } else if (cur_element->right == NULL || cur_element->left == NULL) {
        return NULL;
    }
}

tree_element* SimpleTree::find(int value)
{
    tree_element* cur_root = root;
    if (cur_root != NULL && value == cur_root->value) {
        return(cur_root);
    } else {
        return find1(value, cur_root);
    }
     
}

tree_element* SimpleTree::search(tree_element* elem)
{   
    int A[10];
    int i;
    tree_element* next_elem = elem;
    while (next_elem->value > elem->value){
        A[i]=next_elem->value;
        next_elem = search(elem->right);
    }

    for (i=1; i<10; i++) {
        if (A[i]<A[0]) {
            A[i] = A[0];
        }
        next_elem->value = A[i];
    }
    return(next_elem);
}

tree_element* SimpleTree::search1(tree_element* elem)
{   
    int A[10];
    int i;
    tree_element* next_elem = elem;
    while (next_elem->value < elem->value){
        A[i]=next_elem->value;
        next_elem = search1(elem->left);
    }

    for (i=1; i<10; i++) {
        if (A[i]>A[0]) {
            A[i] = A[0];
        }
        next_elem->value = A[i];
    }
    return(next_elem);
}

void SimpleTree::remove(int value)
{
    tree_element* elem = this->find(value); // здесь были удалены два ненужных printf-а

    if(elem == NULL)
    {                                       // и здесь тоже
        return;
    } else if(elem->left==NULL && elem->right==NULL) {
        if (elem->parent->left== elem){
            delete(elem);
            printf("%d\n", elem->parent->left->value);
            elem->parent->left=NULL;
        } else if(elem->parent->right == elem) {
            delete(elem);
            printf("элемент здесь\n");
            printf("%d\n", elem->parent->right->value);
            elem->parent->right=NULL;
        }
    } else if (elem->left!=NULL || elem->right!=NULL) {
        if (elem->left!=NULL && elem->right == NULL) { //добавлено второе условие
            if (elem->value < elem->parent->value) {
                elem->parent->left = elem->left;       //теперь указатель указывает куда нужно
                delete(elem);
            } else if (elem->value > elem->parent->value) {
                elem->parent->right = elem->left;
                delete(elem);
            }
        } else if (elem->right!=NULL && elem->left == NULL) {  //здесь добавлено условие для корневого элемента
            if (elem->parent != NULL) {
              if (elem->value < elem->parent->value){
                  elem->parent->left = elem->right;
                  delete(elem);
              } else if (elem->value > elem->parent->value){
                  elem->parent->right = elem->right;
                  delete(elem);
              }
            } else if (elem->parent == NULL) {
                elem->right->parent == NULL;
                delete(elem);
        } else if (elem->left!=NULL && elem->right!=NULL) {
            if (elem->left != NULL) {
                if (elem->value < elem->parent->value) {
                    elem->parent->left = search1(elem);
                    delete(elem);
                } else if (elem->value > elem->parent->value) {
                    elem->parent->left = search(elem);
                    delete(elem);
                } else if (elem->right != NULL) {
                    if (elem->value < elem->parent->value) {
                    elem->parent->left = search1(elem);
                    delete(elem);
                } else if (elem->value > elem->parent->value) {
                    elem->parent->left = search(elem);
                    delete(elem);
                }
                }
            }
        }
    }
}

void SimpleTree::print_element(tree_element* cur_elem) {
    // printf("2\n");
    printf("%d\n", cur_elem->value);
    if (cur_elem->left != NULL) {
        // printf("2\n");
        print_element(cur_elem->left);

    }
    // printf("%d\n", cur_elem->value);
    if (cur_elem->right != NULL) {
        print_element(cur_elem->right);
    }
    // printf("%d\n", cur_elem->value);
    // printf("2\n");
}
void SimpleTree::print() 
{
    tree_element* cur_elem = this->root;
    print_element(cur_elem);
}
