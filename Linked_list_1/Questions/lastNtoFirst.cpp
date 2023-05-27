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
//suppose LL has 5 elements
//and n=3. means we have to put last 3 nodes to first
Node* LasttoFirst(Node* head,int n){
    Node* temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    //length will give us number of elements in LL = 5
    int count = length-n;//2. that means we have to stop at second node or index 1 and point it to NULL
    Node* curr = head;
    Node* head2 = NULL;
    for(int i=0;i<count;i++){//i will have 0 and 1.
        if(i == count-1){
            head2 = curr->next;//head2 will be the third node address(or index 2 address)
            curr->next = NULL;//pointing the node at index 1 to NULL
        }
        curr = curr->next;//do this till we reach the node at count(at index count-1)
    }
    
    //!so we are breaking the LL into 2 parts. First the node at count(2nd node here) will point to null.we save the address of its
    //!next in head2. which will be our new head.

    //head2 will be our new head.
    Node* tail = head2;
    while(tail->next != NULL){
        tail=tail->next;
    }
    //tail will have the address of the 5th node or 4 index
    //now putting tail->head instead of NULL
    tail->next = head;
    return head2;
}

int main(){
    Node* head = takeInputBetter();
    print(head);
    Node* newhead = LasttoFirst(head,3);
    cout<<endl;
    print(newhead);
}