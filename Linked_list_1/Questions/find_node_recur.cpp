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

int Find_Node(Node* head,int data,int index){
    int count = 0;
    int exist = 0;  
    if(head == NULL){//if not found throughout -1 will be returned
        return -1;
    }
    if(head->data ==data){//if it is found the current value of index will be returned 
    //and function will end
        return index;
    }
    //index+1 will be done and next node will be looked at
    return Find_Node(head->next,data,index+1);
}   //we put index as 0 when we call the function
//it is a very good way to find at what index the node was found
int main(){
    Node* head = Take_Input();
    int n = Find_Node(head,4,0);
    cout<<n;

}