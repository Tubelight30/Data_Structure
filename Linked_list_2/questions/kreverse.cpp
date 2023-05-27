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

Node* kreverse(Node* head,int k){
    if(head == NULL){
        return NULL;
    }
    int count = 0;
    Node* curr = head;
    Node* prev = NULL;
    Node* nxt = NULL;
    //normal iteration to reverse the first k nodes. we get prev as the new head.
    while(curr!=NULL && count<k){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }
    //the nxt now points to (k+1)th node and the head we got now the last node and 
    //the new head is prev.we use recursion and join the rest LL to the head->next
    if(nxt!=NULL){
        head->next = kreverse(nxt,k);
    }
    return prev;
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
    Node* head2 = kreverse(head,3);
    print(head2);

}