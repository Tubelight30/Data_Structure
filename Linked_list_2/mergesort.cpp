//!mergesort a LL(Divider and Conquer)
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

Node* mergeSortedLL(Node* h1,Node* h2){
    Node* finalh = NULL;
    Node* finalt = NULL;
    if(h1->data<=h2->data){
        finalh=h1;
        finalt=h1;
        h1 = h1->next;
    }
    else{
        finalh=h2;
        finalt=h2;
        h2= h2->next;
    }
    while(h1!=NULL && h2!=NULL){//if any one is NULL loop will break
        if(h1->data>h2->data){
            finalt->next=h2;
            h2 = h2->next;
            finalt = finalt->next;
        }
        else{
            finalt->next=h1;
            h1= h1->next;
            finalt = finalt->next;
        }
    }
    if(h1 != NULL){
        finalt->next=h1;
    }
    if(h2!=NULL){
        finalt->next = h2;
    }
    return finalh;
}
//mergesort runs in O(n logn)
Node* mergesort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    //using two pointer approach to find midpoint
    Node* slow = head;
    Node* fast = head->next;
    //we start fast from head->next instead of head 
    //bcz in head->next slow will give the first midpoint in even nodes
    //and head will give us the second midpoint but here for we need first midpoint for optimal 
    //spilitting of the list
    while(fast!=NULL && fast->next!=NULL){
        fast= fast->next->next;
        slow = slow->next;
    }
    //now slow is the mid
    Node* head2 = slow->next;//as head2 is mid->next 
    
    slow->next = NULL;//breaking the LL after mid into 2
    Node* newHead = mergeSortedLL(mergesort(head),mergesort(head2));
    return newHead;
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
    Node* head2 = mergesort(head1);
    print(head2);

}
