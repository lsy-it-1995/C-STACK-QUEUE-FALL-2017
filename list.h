#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>

using namespace std;

template <class T>
struct node{
    T _item;
    node<T>* _next;
    node();
    node(const T& item = T(), node<T>* next = NULL):_item(item), _next(next){}
    friend ostream& operator << (ostream& outs, const node<T>& print_me)
    {
        outs<<"["<<print_me._item<<"]->";
        return outs;
    }
};

//initializes head to NULL
template <class T>
node<T>* init_head(node<T>* &head)
{
    //making head =nothing;
    return head=NULL;
}

//deletes all the nodes in the list
template<class T>
void delete_all(node<T>* &head)
{
    while(head!=NULL)
        delete_head(head);
}

//true if head is NULL, false otherwise.
template <class T>
bool empty(const node<T>* head)
{
    if(head==NULL)
        return true;//check head has nothing
    else
        return false;//head has something
}

//makes a copy of the list, returns a pointer to the last node:
template <class T>
node<T>* copy_list(const node<T>* head, node<T>* & cpy)
{
    assert(head);
    node<T> *walkercpy = NULL;
    while(head)
    {

        walkercpy = insert_after(cpy,walkercpy,head->_item);
        head=head->_next;
    }
    return walkercpy;
}

//insert at the beginning of the list:
template <class T>
node<T>* insert_head(node<T>* &head, T item)
{
    //creating a node(item). the node's item = item.  the next node = head.
    //let head = node ; back to head;
    //basically creating a node to switch the order of head
    node<T> *temphead = new node<T>(item);
    temphead->_next=head;
    head = temphead;
    return head;
}

//insert_after: if after is NULL, inserts at head
template <class T>
node<T>* insert_after(node<T>* &head, node<T>* &after, const T& item)
{
    if(head==NULL)
    {
        return insert_head(head,item);
    }
    else
    {
        return insert_head(after->_next,item);
    }

    //case 1
    //check the condition if after is NULL, we need to insert at thead

    //case 2
    //if head!=NULL(!empty) creating a node.
    //let the node becomes after the last one(also carry the item)
}


//delete the node at the head of the list, return the item:
template <class T>
T delete_head(node<T>* &head)
{
    assert(head);
    node<T> *temp;
    T item1;
    temp = head;
    item1 = head->_item;
    head = temp->_next;
    delete temp;
    return item1;
}

//print the list and return outs
template<class T>
ostream& print_list(const node<T>* head, ostream& outs=cout)
{
    while(head)
    {
        outs<<"[";
        outs<<head->_item;
        outs<<"]->";
        head=head->_next;
    }
    outs<<"|||";
    return outs;
}

#endif // LIST_H
