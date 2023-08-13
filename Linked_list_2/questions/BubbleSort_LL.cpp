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
int length(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
Node* bubble(Node* head){
    int L = length(head);
    int i = 0;
    while(i<L)
    {
        Node* curr = head;
        Node* prev = head;
        while(curr->next!=NULL)
        {
            Node* temp = curr->next;
            if(curr->data>temp->data)
            {
                if(curr == head)
                {//swapping and updating head of LL
                    curr->next = temp->next;
                    temp->next = curr;
                    prev = temp;
                    head = prev;
                }
                else
                {//only swapping
                    curr->next = temp->next;
                    temp->next = curr;
                    prev->next = temp;
                    prev = temp;
                }
                continue;
                //straight away goes to inner while loop again.
                //now the curr.data is not > temp.data so the if condi is not executed.
                //prev = curr statement is executed.
            }
            prev = curr;
            curr = curr->next;
        }
        i++;
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
    Node* head2 = bubble(head);
    print(head2);


}