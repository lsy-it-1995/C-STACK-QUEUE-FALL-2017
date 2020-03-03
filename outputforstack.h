#ifndef OUTPUTFORSTACK_H
#define OUTPUTFORSTACK_H
#include <iostream>
#include "stack.h"

using namespace std;

void teststack()
{
    cout<<"here is for stack"<<endl;
    Stack<int> mystack1;
    for(int i =0;i<10;i++)
        mystack1.push(i);
    cout<<"q1 :"<<mystack1<<endl;
    Stack<int> mystack2(mystack1);
    cout<<"q2 :" <<mystack2<<endl;
    while(!mystack1.empty())
    {
        cout<<"{"<<mystack1.pop()<<"} ";
        cout<<mystack1<<endl;
        cout << endl;
    }
    mystack1=mystack2;
    cout<< "q1 "<<mystack1<<endl;
    cout << "q2 "<<mystack2<< endl;
}

#endif // OUTPUTFORSTACK_H
