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
//!Now to insert node at ith position in a linked list
//!parameters are head , data we want to insert and a the position i
Node* insertNode(Node* head,int data,int i){
    Node* newnode = new Node(data);
    int count = 0;
    Node* temp = head;
    if(i == 0){//special condition when i = 0 we directly need to place newnode at beginning
        newnode->next = head;
        head = newnode;//head also needs to be updated to this new beginning
        //now this new head also has to returned so that we can print this new linked list
        return head;//return type of function has to be changed from void to Node* as we return head;
    }
    //temp != NULL for when i > total no. of nodes in linked list
    //if i>no. of nodes temp will = NULL after last node as temp=lastnode->next = NULL
    while(temp != NULL && count < i-1){
        temp = temp->next;
        count++;
    }
    //in temp we have detail of our (i-1)th node

    //we connected i-1 to newnode using 'a' and then newnode to i
    //these only have to run when temp != NULL
    if(temp != NULL){
        Node* a = temp->next;//saving the location of our ith node.
        temp->next = newnode;//contecting i-1 to newnode
        newnode->next = a;//connecting newnode to i
    }
    //we connected our newnode to i
    // temp->next = newnode; we connected i-1 to new node

    //we now have to return head as return type of function has changed so we return original head when i !=0
    return head;
}

int main(){
    Node* head = takeInputBetter();
    print(head);
    int i,data;
    cin>>data>>i;
    head = insertNode(head,data,i);//when i = 0 we will get new head , otherwise we will getback the old head
    print(head);

}