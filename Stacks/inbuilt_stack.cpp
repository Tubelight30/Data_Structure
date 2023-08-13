#include <iostream>
#include <stack>
using namespace std;
//we use inbuilt stack class
//we can use inbuilt stack class for any data type it is template class.
//it is almost same as our stack class.
//but the pop function is void in inbuilt stack class.
//so we cannot print the element which is poped.
//isEmpty() is empty() in inbuilt stack class.
//
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30); 
    s.push(40);
    s.push(50);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.size()<<endl;   
    cout<<s.empty()<<endl;
}