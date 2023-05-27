#include<iostream>
using namespace std;
//!We have to find the length of a LL recursively
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
int lengthLL(Node* head){
    int count = 0;
    if(head == NULL){
        return count;
    }
    else{
        head = head->next;
        count++;
        return (count + lengthLL(head));
    }
}
int main(){
    Node* head = takeInputBetter();
    print(head);
    int counting = 0;
    counting = lengthLL(head);
    cout<<endl;
    cout<<counting;

}