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
void print(Node* head){
    cout<<"The linked list is "<<endl;
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
Node* delete_recursive(Node* head,int i){
    if(i==0){
        head = head->next;
        return head;
    }
    if(i ==1){
        Node* a = head->next;
        head->next = a->next;
        return head;
    }
    if(head == NULL){
        return NULL;
    }
     
    Node* curr = delete_recursive(head->next,i-1);
    return head;
}
int main(){
    Node* head = takeInputBetter();
    print(head);
    head = delete_recursive(head,2);
    print(head);

}