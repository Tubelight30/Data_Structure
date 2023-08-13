#include<iostream>
using namespace std;
//!instead of asking the user for the total size of the stack, we will create a stack of size 4.
//!if the user wants to add more elements, we will create a new stack of double size and copy the elements from the previous stack to the new stack.
//!this is called dynamic stack.

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity; //total size of stack
    public:
    StackUsingArray(){
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
    }
    //return the number of elements presents in my stack
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
       return nextIndex == 0;
    }
    //insert element
    void push(int element){
        if(nextIndex == capacity){
            int *newData = new int[2 * capacity];
            for(int i = 0;i<capacity;i++){
                newData[i] = data[i];
            }
            capacity*=2;
            delete [] data;//delete the previous array and point it to the new array
            //this does not delete the variable, it just deletes the array.
            //data now points to the new array.
            data = newData;
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
    StackUsingArray s;//!total size of stack is 4
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);// this will create a new stack of size 8 and copy the elements from the previous stack to the new stack.      
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;

}