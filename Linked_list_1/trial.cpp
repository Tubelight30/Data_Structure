#include<iostream>
using namespace std;
//!PRACTICE PAGE
//!this is just me trying to practice writing on my own.........
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

Node *takeInput(){
    int data;
    cin>>data;
    Node *head= NULL;
    while(data !=-1){
        Node *newNode = new Node(data);
        if(head== NULL){
            head = newNode;
        }
        else{
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head){
    cout<<"The linked list is"<<endl;
    Node *temp = head;
    while (temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;   
    }
};

int main(){
    Node *n1 = takeInput();
    print(n1);
}
