#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int Data){
    data = Data;
    next = NULL;
    }
};

Node* takeInputBetter(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data !=-1){
        Node* newnode = new Node(data);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
        cin>>data;
    }
    return head;
}

int FindNode_recur(Node* head,int n){
    int index = 0;
    if(head->data==n){
        return index++;
    }
    if(head->next == NULL && head->data!=n){
        return -1;
    }
    index++;
    if(FindNode_recur(head->next,n)==-1){//if findnode_recur is -1 then there will be no
    //index+findnode straight the answer will be -1.
        return -1;
    }
    else{
        return index+FindNode_recur(head->next,n);
    }

}


void print(Node* head){
    cout<<"The linked list is "<<endl;
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* head = takeInputBetter();
    print(head);
    cout<<endl;
    int num=FindNode_recur(head,2);
    cout<<num;

}