#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;//creating a custom pointer for keeping the address of the next node.

    Node(int Data){//a constructor
        data = Data;
        next = NULL;
    }
};

//!Full Explanation in Linked_list3_explanation.md 
Node *takeInput_Better(){
    int data;
    cin>>data;
    Node *head=NULL;//right now list is empty
    Node *tail=NULL;//creating a tail
    while(data != -1){
        //Node n(data);cannot create statically here as with every while loop
        // our linked list will start from beginning everytime
        //so we use dynamic allocation.
        Node *newnode = new Node(data);
        if(head == NULL){/*we only want to assign head only 1 time so after 1 iteration
                        head will not be null and will have the starting address of linked list*/
        head = newnode;
        //only 1 element so tail should also be the newnode;
        tail = newnode;
        }
        else{
            // Traverse the Whole linked list until the last node is reached
            //!this is inefficient(complexity is O(n^2))as we are to we are iterating to last node of list everytime to find its
            //!address to attach a new node
            //! so we can make a tail which already has address of last node so we won't have to iterate and while can be removed.
            //!basically our temp was acting as a tail but now we make an official tail
            // Node *temp= head;
            // while(temp->next!=NULL){
            //     temp = temp->next;
            // }             
            //Add the new node to the end of the linked list
            // temp->next= newnode;
            
            //we need just this statement and each node will have its node's address.
            tail->next = newnode;
            tail = tail->next;

        }
        cin>>data;
    }
    return head;
}

void print(Node *head){
    cout<<"The linked list is"<<endl;
    Node *temp = head;
    while (temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;   
    }
};

int main(){
    Node *head = takeInput_Better();
    //-1 to stop the takeInput loop and -1 will not a part of the linked list
    //use our print function to print the whole linked list
    print(head);
    
}
