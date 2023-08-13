#include<iostream>
using namespace std;

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity; //total size of stack
    public:
    StackUsingArray(int totalSize){
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }
    //return the number of elements presents in my stack
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        /*
        if(nextIndex == 0){
            return true;
        }
        else{
            return false;
        }
        */
       return nextIndex == 0;
    }
    //insert element
    void push(int element){
        if(nextIndex == capacity){
            cout<<"Stack is full"<<endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    
    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    int top(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex - 1]; 
    }   

};
int main(){
    StackUsingArray s(4);//!total size of stack is 4
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);// stack is full so it will not insert 6      
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;

}