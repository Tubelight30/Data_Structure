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

Node* reverse(Node* h1){
    if(h1 == NULL || h1->next == NULL){
        return h1;
    }
    //iterative way
    // Node* prev = NULL;
    // Node* curr = h1;
    // Node* nxt = NULL;
    // while(curr!=NULL){
    //     nxt = curr->next;
    //     curr->next = prev;
    //     prev = curr;
    //     curr = nxt;
    // }
    //return prev;
    //!this approach has approx O(n^2) time complexity 
    //as we are travelling to the end of the temp with while also everytime.
    Node* rest = reverse(h1->next);
    
    //working:just assume rest returns the reveresed rest of the list, we just have to connect our original 
    //head to the last of the list and done. so we use while to travel
    //now rest is head of the reversed linked list

    Node* temp = rest;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next= h1;//connecting head to the last and pointing its next to NULL
    h1->next = NULL;

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
