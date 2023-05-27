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

//!just like takeInput function we can maintain a tail pointer to keep the last node of the LL
//!then we can add original head to the last node and discard the while loop method to travel
//!so we need to return a head and a tail from the function evertime
//!to return multiple values from a function we use Classes and objects
class Pair{
    public:
    Node* head;
    Node* tail;
};
//creating a function with return type Pair
Pair reverseLL(Node* head){
    if(head == NULL || head->next == NULL){
        //return head; cannot return as return type is Pair
        Pair ans;//creating obj
        ans.head = head;
        ans.tail = head;
        return ans;
        //when length of LL is 0 or 1 both head and tail are same and point to head.
    }
    Pair rest = reverseLL(head->next);
    //assume that rest has the reveresed rest of LL. we need to join the original head to the end
    //tail has the last node of rest. and then the original head is the tail now.
    //basically same thing as reverse_nodes_recur but without while loop.

    rest.tail->next = head;//inserting head after tail and changing the tail
    rest.tail = head;
    head->next = NULL;

    //this function now returns both head and tail so we fix that using another function
    return rest;
}
Node* reverseLL_Better(Node* head){
    return reverseLL(head).head;
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
   Node* h2 = reverseLL_Better(head1);
   print(h2);
}
