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
//!inserting node recursively
//idexing starts from 0
Node* insert_recursively(Node* head, int data, int i){
    if(head == NULL){//base case when no linked list or head = NULL
        return NULL;
    }
    if(i == 0){//base case of inserting in the beginning:to insert at position 0
        Node* newnode = new Node(data);
        newnode->next = head;
        head = newnode;
        return head;//head will be changed
    }
    if(i == 1){//base case of inserting anywhere(even at end):insert at position 1
    //basically inserts a node in b/w 2 nodes.
        Node* newnode = new Node(data);
        newnode->next = head->next;
        head->next = newnode;
        return head;//no change in head.
    }

    //when i>1 we use recursion. will run till i = 1
    Node* curr = insert_recursively(head->next,data,i-1);
    //easy to visualize but if still not get it then use code visualizer 
    //if i>no. of nodes then the head becomes NULL we also have base case for that
    //curr is only for traversing the list 
    //the final changes are being made in head(if any) as seen in base case
    //so we have to return head so that we can print the LL
    return head;
}

int main(){
    Node* head = takeInputBetter();
    print(head);
    cout<<endl;
    head = insert_recursively(head,99,7);
    print(head);
}