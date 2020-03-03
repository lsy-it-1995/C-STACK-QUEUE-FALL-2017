#ifndef OUTPUTFORQUEUE_H
#define OUTPUTFORQUEUE_H
#include <iostream>
#include "queue.h"
#include <string>
using namespace std;

void testqueue()
{
    Queue<string> myq1;
    Queue<string> myq2;
    myq1.push("a");
    myq1.push("b");
    myq1.push("c");
    myq2.push("a");
    myq2.push("b");
    myq2.push("c");
    if(myq1==myq2)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    //    cout<<"here is output for queue"<<endl;
//    Queue<int> myqueue;

//    for(unsigned int i =0;i<10;i++)
//        myqueue.push(i);

//    Queue<int> myqueue2(myqueue);
//        cout <<"q1 " <<myqueue<<endl;
//        cout <<"q2 " <<myqueue2<<endl;
//        cout << endl;
//    while(!myqueue.empty())
//    {

//        cout<<"{"<<myqueue.pop()<<"} ";

//        cout<<myqueue<<endl;
//        cout << endl;
//    }
//    myqueue=myqueue2;
//    cout<< "q1 "<<myqueue<<endl;
//    cout << "q2 "<<myqueue2 << endl;
}
#endif // OUTPUTFORQUEUE_H
