#include <iostream>
using namespace std;

template <typename T>//will have to mention this line for everyclass
class Node{
    public:
    T data;
    Node<T> *next;
    Node(T data){
        this->data = data;
        next = NULL;
    }
};
//!instead of maintaining a head and tail pointer, we will maintain only a head pointer.
//!we will insert at the head everytime and delete from the head. and change the head pointer 
//!everytime we insert or delete.
//!there are other ways to do this, but this is the most efficient way. this way we can pop with time
//!complexity of O(1).
//we make the new element as the new head and point it to the previous head.
//this way we wont need to maintain a tail pointer or a previous pointer.
//to maintain the size of the stack, we will use a variable called size. to keep complexity of size O(1).
template <typename T>
class Stack{
    Node<T> *head;
    int size;
    public:
    Stack(){
        head = NULL;
        size = 0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void push(T element){
        Node<T> *newnode = new Node<T>(element);
        newnode->next = head;
        head = newnode;
        size++;
    }
    T pop(){
        if(isEmpty()){
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;//moving the head to next node and then dealocating the first og head.
        //we also need to delete the node from the memory.
        delete temp;
        size--;
        return ans;
    }
    T top(){
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }

};
int main(){
    Stack<char> s;
    s.push(102);
    s.push(103);
    s.push(104);
    s.push(105);
    s.push(106);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;
}