//You have been given a singly linked list of integers where the elements are sorted in ascending order. 
//Write a function that removes the consecutive duplicate values such that the given list only contains unique elements 
//and returns the head to the updated list.
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
Node* NoDuplicate(Node* head){
    Node* temp = head;
    if(head == NULL || head->next == NULL){//LL has no elements or just 1 element then simply return head
        return head;
    }
    Node* temp2 = temp->next;
    while(temp->next!= NULL){
        if(temp->data == temp2->data){
            temp2 = temp2->next;
            //as we had dynamically allocated so to collect garbage we also have to deallocate 
            free(temp->next);
            //and then reassign
            temp->next = temp2;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}
int main(){
    Node* head = takeInputBetter();
    print(head);
    cout<<endl;
    Node* newhead = NoDuplicate(head);
    print(newhead);

}
