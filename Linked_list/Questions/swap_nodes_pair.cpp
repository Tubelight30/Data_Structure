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

//!use code visualiser
Node* swapPairs(Node* head) {
        Node* temp = head;
        Node* dummy = new Node(0);
        dummy->next=head;//making a dummy node that points to the head
        Node* prev = dummy;//intially set to dummy

        //!IMP:MAKING CHANGES TO PREV.NEXT WILL MAKE CHANGES IN DUMMY.NEXT
        //!BUT DOING PREV = PREV.NEXT WILL NOT CHANGE DUMMY.
        Node* curr = head;//first node in the pair
        while(curr!=NULL && curr->next !=NULL){//means there are atleast 2 nodes in the LL
            //saving add. of some nodes 
            Node* nxtPair = curr->next->next;//this is the node that that the second node is pointing at
            Node* second = curr->next;//second node in the pair

            //reversing
            second->next = curr;//pointing the second node to first instead of 3rd
            curr->next = nxtPair;//pointing current node to 3rd
            prev->next = second;//makding prev point to second which has now become first
            //so ignoring the dummy node the second node is now the first node

            //the nodes are acutally exhanged
            prev = curr;
            curr = nxtPair;
        }
        //this will point to the new head node
     return dummy->next;
}

int main(){
    Node* head = takeInputBetter();
    print(head);
    cout<<endl;
    Node* head2= swapPairs(head);
    print(head2);
}
