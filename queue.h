#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cassert>
#include <fstream>
#include "list.h"

using namespace std;

template <class T>
class Queue{
public:
    Queue():_head(NULL), _tail(NULL), sizenumber(0){}

    ~Queue();
    Queue(const Queue<T>& other);
    Queue<T> &operator =(const Queue& rhs);
    T operator = (T &rhs)
    {
        rhs = this;
        return rhs;
    }
    void push(T item);
    T pop();
    bool empty();
    T front();
    size_t size() const;

//    friend bool operator < (const Queue<T> &lhs, const Queue<T> &rhs)
//    {
//        return lhs.size()<rhs.size();
//    }
//    friend bool operator == (const Queue<T> &lhs,  Queue<T> &rhs)
//    {
//        bool debug_equal_equal = true;


//        Queue<T> temp_lhs = lhs;
//        Queue<T> temp_rhs = rhs;
//        if(debug_equal_equal) cout<<"lhs. size"<<temp_lhs.size()<<endl;
//        if(debug_equal_equal) cout<<"lhs size number"<<temp_lhs.sizenumber;
//        if(debug_equal_equal)  cout<<"rhs.size"<<temp_rhs.size()<<endl;
//        if(debug_equal_equal) cout<<"rhs size number"<<temp_rhs.sizenumber;

//        size_t count = 0;
//        if(debug_equal_equal) cout<<"temp lhs "<<temp_lhs<<endl;
//        if(debug_equal_equal) cout<<"temp rhs "<<temp_rhs<<endl;
//        if(temp_lhs.sizenumber==temp_rhs.sizenumber)
//        {
//            if(debug_equal_equal) cout<<"temp lhs size number"<<temp_lhs.sizenumber<<endl;
//            if(debug_equal_equal) cout<<"temp rhs size number"<<temp_rhs.sizenumber<<endl;

//            if(debug_equal_equal) cout<<"equal each other"<<endl;
//            for(size_t i = 0 ; i < temp_rhs.sizenumber; i++)
//            {
//                if(temp_lhs.pop()==temp_rhs.pop())
//                {

//                    count++;
//                    if(debug_equal_equal) cout<<"count: "<<count<<endl;
//                }
//            }
//        }
//        if(debug_equal_equal) cout<<"count: "<<count<<endl;
//        if(count == temp_rhs.sizenumber)
//            return true;
//        else
//            return false;
//    }
    friend ostream& operator <<(ostream& outs, const Queue& q)
    {
        return print_list(q._head, outs);
    }

private:
    node<T>* _head;
    node<T>* _tail;
    int sizenumber;
};


template<class T>
Queue<T>::~Queue()
{
    bool debug = false;
    if(debug) cout<<"Queue fire"<<endl;
    delete_all(_head);
}

template<class T>
void Queue<T>::push(T item)
{
    bool debug = true;
    _tail = insert_after(_head,_tail,item);
    sizenumber++;
    if(debug) cout<<"in push size number"<<sizenumber<<endl;
}

template<class T>
T Queue<T>::pop()
{
    assert(_head);
    sizenumber--;
    return (delete_head(_head));
}

template<class T>
bool Queue<T>::empty()
{
    //    if(!_head)
    //        return true;
    //    else
    //        return false;
    return !_head;
}

template<class T>
size_t Queue<T>::size() const
{
    //    int f=0;
    //    while(_head)
    //    {
    //        f++;
    //        delete_head(_head);
    //    }
    //    return f;
    return sizenumber;
}

template<class T>
T Queue<T>::front()
{
    return _tail->_item;
}
template<class T>
Queue<T>& Queue<T>::operator =(const Queue& rhs)
{
    //    if(_head)
    //        cout<<"head"<<_head<<endl;
    //    if(_tail)
    //        cout<<"tail"<<_tail<<endl;
    init_head(_tail);
    init_head(_head);
    //    sizenumber =0 ;
    this->size() = rhs.size();
    if(rhs._head)
        copy_list(rhs._head, _head); //break here
    return *this;
}

template<class T>
Queue<T>::Queue(const Queue<T>& other)  //break here
{
    //    if(_head)
    //        cout<<"head"<<_head<<endl;
    //    if(_tail)
    //        cout<<"tail"<<_tail<<endl;
    init_head(_tail);
    init_head(_head);
    if(other._head)
        copy_list(other._head, _head);

    //*this=other;
}

#endif // QUEUE_H
