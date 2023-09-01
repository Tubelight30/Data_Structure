#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int d){
        data = d;
        prev = NULL;
        next = NULL;
    }
};
Node *InsertAtHead(Node *head,int d){
    Node *newnode = new Node(d);
    newnode->next = head;
    head = newnode;
    return head;
}

void printLL(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}
int main(){
    Node* head = new Node(10);
    Node* temp1 = new Node(20);
    Node* temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    printLL(head);
    Node* newH = InsertAtHead(head,5);
    printLL(newH);
}