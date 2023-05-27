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

//now to print a linked list we just need to pass head to print the 
//whole linked list
//we create a func and pass head which has address of n1
void print(Node *head){
    cout<<"The linked list is"<<endl;
    Node *temp = head;
    while (temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;   
    }
};

int main(){
    //!statically making a linked list with 5 nodes
    // Node n1(1);
    // Node *head = &n1;
    
    // Node n2(2);
    // Node n3(3);
    // Node n4(4);
    // Node n5(5);

    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;
    //as n5 is last it should have the next as NULL
    
    //!print(head);this is our custom fucntion we built to print the whole linked list 
    //!now the head = NULL so we have lost the address of head in our func print
    //!now we cannot use the 'head' inside the func to do more list operation in the func
    //!the main func head is still there but our print func 'head' = Null now.
    //!this is not good so we have to use a temp var. in our function itself
    //now the head inside the func is not lost and reusable;
    //print(head);
    //now head address is reatained
    //cout<<head->data;

    //!Dynamically creating the linked list
    Node *n1 = new Node(1);
    Node *head = n1;
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    //now we have to connect them
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    print(head);//using our custom function

}
