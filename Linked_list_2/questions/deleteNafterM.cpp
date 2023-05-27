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

Node* deleteMN(Node* head,int m,int n){
    Node* temp1  = head;
    if(m==0){
        return NULL;
    }
    while(temp1!= NULL){
        for(int i = 1;i<m && temp1!=NULL;i++){
            temp1 = temp1->next;
        }
        if(temp1 ==NULL){
            return head;
        }
        Node* temp2 = temp1->next;
        for(int j = 1;j<n && temp2!=NULL;j++){
            Node* temp = temp2;
            temp2 = temp2->next;
            // free(temp);
        }
        if(temp2 != NULL){
            temp2 = temp2->next;
        }
        temp1->next = temp2;
        temp1  = temp2;
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

int main(){
    Node* head = takeInputBetter();
    print(head);
    cout<<endl;
    Node* head2 = deleteMN(head,4,0);
    print(head2);

}