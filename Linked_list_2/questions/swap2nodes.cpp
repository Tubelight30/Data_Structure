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
//very easy just dry run it once.
//!edge cases not handled here will handle them later.
Node* swap2nodes(Node* head,int node1,int node2){ //1 2 3 4 5 6
    Node* prev1 = head;
    Node* prev2 = head;
    if(node1 == node2){
        return head;
    }
    for(int i = 1;i<node1;i++){
        prev1 = prev1->next;
    }
    for(int j = 1;j<node2;j++){
        prev2 = prev2->next;
    }
    //Node* curr2 =  prev2->next;
    if(prev1 == head){
        head =  prev2->next; 
    }

    // Node* nxt1 = curr1->next;
    // Node* nxt2 =  curr2->next;

    // prev1->next = curr2;
    // curr2->next = nxt1;

    // prev2->next = curr1;
    // curr1->next = nxt2;

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

int main(){
    Node* head = takeInputBetter();
    print(head);
    cout<<endl;
    Node* head2 = swap2nodes(head,1,3);
    print(head2);

}