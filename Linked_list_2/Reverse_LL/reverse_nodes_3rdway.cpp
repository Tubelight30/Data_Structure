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

Node* reverse(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* rest = reverse(head->next);
    //suppose the LL is 1->2->3->4->NULL and 
    //!assume rest has reversed LL and the last node is 2
    //!if we realize that the tail(which is 2) was actually the next of the head all along,we can directly equate it to tail
    //there is no need for class and everyting.

    Node* tail=head->next;//tail = 1->next = 2;

    tail->next = head;//now putting the head after tail as the head will be the last node now
    head->next = NULL;//pointing head to null

    return rest;
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
   Node* h2 = reverse(head1);
   print(h2);
}
