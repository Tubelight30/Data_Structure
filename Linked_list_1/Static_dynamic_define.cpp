#include<iostream>
using namespace std;

//I have used classes but struct can also be used.We in C++ so enjoy C++
class Node{
    public:
    int data;
    Node *next;//creating a custom pointer for keeping the address of the next node.

    Node(int Data){//a constructor
        data = Data;
        next = NULL;
    }
};

int main(){
    //!statically defining a node
    Node n1(1);// a node with 1 as data and next = NULL
    
    Node *head = &n1;//storing address of head in a pointer
    //since it is an address of node thus Node * is used.
    

    Node n2(2);// a node with data =2 and next = NULL

    //now nodes are created but these 2 are not connected 
    //as 1st node has next address =  NULL
    n1.next = &n2;
    //now printing data
    cout<<n1.data<<" "<<n2.data;

    //!Dynamically defining a node
    //consider this a new linked list we are creating so we need to save address of head
    Node *n3 = new Node(30);
    Node *head = n3;
    Node *n4 = new Node(40);

    //(*n3).next = n4; also means the same thing as below
    //as n3 is pointer so we use ->
    n3->next = n4;
    

}