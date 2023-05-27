//!merge 2 sorted LL such that final LL will be sorted
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int Data){
        data = Data;
        next = NULL;
    }
};
Node *takeInput_Better(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data != -1){
        Node *newnode = new Node(data);
        if(head == NULL){
        head = newnode;
        tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = tail->next;

        }
        cin>>data;
    }
    return head;
}

Node* merge(Node* h1,Node* h2){
    Node* finalh = NULL;
    Node* finalt = NULL;
    if(h1->data<=h2->data){
        finalh=h1;
        finalt=h1;
        h1 = h1->next;
    }
    else{
        finalh=h2;
        finalt=h2;
        h2= h2->next;
    }
    while(h1!=NULL && h2!=NULL){//if any one is NULL loop will break
        if(h1->data>h2->data){
            finalt->next=h2;
            h2 = h2->next;
            finalt = finalt->next;
        }
        else{
            finalt->next=h1;
            h1= h1->next;
            finalt = finalt->next;
        }
    }
    if(h1 != NULL){
        finalt->next=h1;
    }
    if(h2!=NULL){
        finalt->next = h2;
    }
    return finalh;
}

void print(Node *head){
    cout<<"The linked list is"<<endl;
    Node *temp = head;
    while (temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;   
    }
    cout<<endl;
};

int main(){
    Node* head1 = takeInput_Better();
   // print(head1);
    Node* head2 = takeInput_Better();
    Node* head3 = merge(head1,head2);
    print(head3);
    
}
