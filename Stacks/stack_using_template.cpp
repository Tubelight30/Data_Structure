#include<iostream>
using namespace std;

template <typename T>
class StackUsingArray{
    T *data;
    int nextIndex;
    int capacity; //total size of stack
    public:
    StackUsingArray(){
        data = new T[4];
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
    void push(T element){
        if(nextIndex == capacity){
            T *newData = new T[2 * capacity];
            for(int i = 0;i<capacity;i++){
                newData[i] = data[i];
            }
            capacity*=2;
            delete [] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    
    T pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            //!return INT_MIN;
            return 0;//return 0 because is standard for int or double or char
        }
        nextIndex--;
        return data[nextIndex];
    }
    T top(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            //!return INT_MIN;
            return 0;//return 0 because is standard for int or double or char
        }
        return data[nextIndex - 1]; 
    }   

};
int main(){
    StackUsingArray<char> s;//!total size of stack is 4
    s.push(102);//will be converted to char. 102 is the ASCII code for f.
    s.push(103);
    s.push(104);
    s.push(105);
    s.push(106);// this will create a new stack of size 8 and copy the elements from the previous stack to the new stack.      
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;

}