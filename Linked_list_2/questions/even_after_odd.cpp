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

Node* eveOdd(Node* head){
    Node* temp = head;
    Node* oddh=NULL;
    Node* oddt = NULL;
    Node* evenh = NULL;
    Node* evenT = NULL;
    while(temp!=NULL){
        if(temp->data%2!=0 && oddh==NULL){
            oddh = temp;
            oddt = temp;
        }
        else if(temp->data%2!=0 && oddh!=NULL){
            oddt->next = temp;
            oddt = oddt->next;
        }
        else if(temp->data%2==0 && evenh==NULL){
         evenh = temp;
         evenT = temp;
        }
        else if(temp->data%2==0 && evenh!=NULL){
         evenT->next = temp;
         evenT = evenT->next;
        }
        temp = temp->next;
    }
    //if LL was 1 2 3 4 5 NULL
    //then even LL will have 2 4 and evenT will be 4 but 4 is still joined to 5 so evenh will print 5
    //as well.this can happen in both so we make the next of tail = NULL if the tail itself is not 
    //NULL.
    if(oddt!=NULL){
        oddt->next = NULL;
    }
    if(evenT!=NULL){
        evenT->next = NULL;
    }
    if(oddh == NULL){
        return evenh;
    }
    else{
        oddt->next = evenh;
        return oddh;
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
    Node* head2 = eveOdd(head);
    print(head2);

}