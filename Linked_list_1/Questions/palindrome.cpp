#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int Data){
        data=Data;
        next=NULL;
    }
};
Node* takeInputBetter(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data !=-1){
        Node* newnode=new Node(data);
        if(head==NULL){
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
bool isPali(Node *head){
    Node* fast = head;
    Node* slow = head;

    //!for finding middle (slow)
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    //slow will have the mid

    //!reverse second half
    //Suppose the second half is 3->2->1->NULL. thus slow is 3
    Node *prev = NULL;
    Node* temp = NULL;
    while(slow!=NULL){//slow is the current mid node
        temp = slow->next;//create a temp with address of next.
        slow->next = prev;//change the next of this node to point the previous node.in first iteration prev node is NULL(3 points to NULL)
        prev = slow;//then change prev to the current node as the next node will point to this previous.(prev is now 3 is instead of null)
        slow = temp;//now slow is at next node using the address we saved in temp
    }
    //The LL is 1->2->3->NULL
    //now the 2nd half is reversed and its head is prev.
    //!comparing both halves. 
    Node *temp1 = head;//to avoid changing the actual LL
    //we might need to print or use it later
    while(prev!=NULL){
        if(temp1->data != prev->data){
            return false;
        }
        prev=prev->next;
        temp1= temp1->next;
    }
    //if outside loop means all values match
    return true; 
}

void print(Node* head){
    cout<<"The linked list is"<<endl;
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main(){
    Node *head = takeInputBetter();
    Node* temp2 = head;
    print(head);
    bool ans = isPali(head);
    cout<<ans<<endl;
    print(head);

}