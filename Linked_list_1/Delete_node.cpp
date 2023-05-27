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

Node* insertNode(Node* head,int data,int i){
    Node* newnode = new Node(data);
    int count = 0;
    Node* temp = head;
    if(i == 0){
        newnode->next = head;
        head = newnode;
        return head;
    }
    while(temp != NULL && count < i-1){
        temp = temp->next;
        count++;
    }
    if(temp != NULL){
        Node* a = temp->next;
        temp->next = newnode;
        newnode->next = a;
    }
    return head;
}

Node* DeleteNode(Node* head,int i){
    if(i == 0){
        head = head->next;
        return head;
    }
    int count = 0;
    //suppose we want to delete i = 2
    Node* temp = head;
    //again we give contion for when i>no. of nodes 
    while(temp != NULL && count<i-1){
        temp = temp->next;
        count++;
    }
    if(temp != NULL){
        Node* a = temp->next;
        temp->next = a->next;//temp->next directly pointing to a->next. "a" skipped
        //now 'a' of no use so as we created nodes dynamically we should deallocate also
        delete a;
    }
    return head;

}
int main(){
    Node* head = takeInputBetter();
    print(head);
    int i,data;
    cin>>data>>i;
    head = insertNode(head,data,i);//when i = 0 we will get new head , otherwise we will getback the old head
    print(head);
    cin>>i;
    head = DeleteNode(head,i);
    print(head);

}