#include <iostream>
using namespace std;//this order is important
//we have to do iostream and namespace std before including the header file.
#include "QueueUsingArray.h"
int main(){
    QueueUsingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);//queue is full
    cout<<q.front()<<endl;//10
    cout<<q.dequeue()<<endl;//10
    cout<<q.dequeue()<<endl;//20
    cout<<q.dequeue()<<endl;//30
    cout<<q.getSize()<<endl;//2
    cout<<q.isEmpty()<<endl;//0
    
}