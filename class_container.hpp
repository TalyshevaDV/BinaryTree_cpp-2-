
#ifndef Container_h
#define Container_h  
#include <iostream>
  
using namespace std;

// Интерфейс
class Container
{
public:
    // Виртуальные методы, будут реализованы далее 
    virtual void insert(int value) = 0;
    virtual bool exists(int value) = 0;
    virtual void remove(int value) = 0;
    // Это потом заменим на перегруженный оператор <<
    virtual void print() = 0;

    // Виртуальный деструктор
    virtual ~Container();
};
#endif