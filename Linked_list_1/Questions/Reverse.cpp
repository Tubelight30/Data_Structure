// You have been given a singly linked list of integers. Write a function to print the list in a reverse order.
//you need to start printing the data from the tail and move towards the head of the list, 
//printing the head data at the end.
// Note :
// You can’t change any of the pointers in the linked list, just print it in the reverse order.
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
void Reverse(Node* head){
    if(head == NULL){
        return; 
    }
    Reverse(head->next);
    cout<<head->data<<" ";//this line will no execute till the reverse function has returned something;
    //so after NULL is reached and return; is executed then one by one cout will start to execute 

}

int main(){
    Node* head = takeInputBetter();
    print(head);
    cout<<endl;
    Reverse(head);
}
