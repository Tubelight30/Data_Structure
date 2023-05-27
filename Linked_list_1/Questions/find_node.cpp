#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int Data){
        data=Data;
        next=NULL;
    }
};

Node* Take_Input(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1){
        Node* newnode = new Node(data);
        if(head == NULL){
            head= newnode;
            tail = newnode;
        }
        else{
            tail->next=newnode;
            tail = newnode;
        }
        cin>>data;
    }
    return head;
}

int Find_Node(Node* head,int data){
    Node* temp = head;
    int index=0;
    while(temp != NULL){
        if(temp->data == data){
            return index;
        }
        index++;
        temp = temp->next;
    }
    if(temp == NULL){
        return -1;
    }
}
int main(){
    Node* head = Take_Input();
    int n = Find_Node(head,9);
    cout<<n;
}