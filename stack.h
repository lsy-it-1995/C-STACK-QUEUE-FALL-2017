#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>
#include <cassert>
#include "list.h"

using namespace std;

template <class T>
class Stack{
public:
    Stack():_top(NULL){}

    ~Stack();
    Stack(const Stack<T>& other);
    Stack<T>& operator =(const Stack<T>& rhs);

    void push(T item);
    T pop();
    T top();
    bool empty();
    friend ostream& operator << (ostream& outs, const Stack& s){
        return print_list(s._top, outs);
    }
private:
    node<T>* _top;
};

template <class T>
Stack<T>::~Stack()
{
    delete_all(_top);
}

template <class T>
Stack<T>::Stack(const Stack<T>& other)
{
    init_head(_top);
    if(other._top)
        copy_list(other._top, _top);
}

template <class T>
Stack<T>& Stack<T>:: operator =(const Stack<T>& rhs)
{
    init_head(_top);
    copy_list(rhs._top, _top); //break here
    return *this;
}

template <class T>
void Stack<T>::push(T item)
{
    insert_head(_top,item);
}

template <class T>
T Stack<T>::pop()
{
    assert(_top);
    return delete_head(_top);
}

template <class T>
T Stack<T>::top()
{
    return _top->_item;
}

template <class T>
bool Stack<T>::empty()
{
    return !_top;
}


#endif // STACK_H
