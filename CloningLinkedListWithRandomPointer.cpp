/*
    Focus is your utmost priority :)
    -> Very important problem to when introduce the dummy node and to when use the three pointers :)
*/
/*https://youtu.be/_GBo_CgST1M?si=QjSvnmp-uJYakq_7*/ // -> Link where You can Find the detailed and Dedicated Video

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int val;
    node* next;

    node(int _val){     // constructor
        val = _val;
        next= NULL;
    }
};  

void insert_tail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;

    while(temp -> next != NULL){
        temp = temp -> next;
    }   

    temp -> next = n;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp -> next;
    }
    cout << endl;
}

node* reverse(node* &head, int left, int right){
    // Creating a dummy node to handle all the cases whether there is some node before Head or Not {Edge cases}
    node* DummyNode = new node(-1);
    DummyNode -> next = head;

    // Marking current node and prev Node
    node* left_prev = DummyNode;
    node* curr_ptr = head;

    for(int i=0; i<left-1; i++){            // Taking curr pointer to the node from where we have to reverse the list 
        left_prev = curr_ptr;
        curr_ptr  = curr_ptr -> next;
    }

    // Marking the head of the sub-list which we have to reverse :))
    node* sublist_head = curr_ptr;
    node* prev_ptr = NULL;
    for(int i=0; i<right-left+1; i++){
        node* next_ptr = curr_ptr -> next;
        curr_ptr -> next = prev_ptr;
        prev_ptr = curr_ptr;
        curr_ptr =  next_ptr;
    }

    // Combining the left over parts <<--
    left_prev->next = prev_ptr;
    sublist_head->next = curr_ptr;

    return DummyNode->next;
}

int main(){
    node* head = NULL;
    insert_tail(head, 1);
    insert_tail(head, 2);
    insert_tail(head, 3);
    insert_tail(head, 4);
    insert_tail(head, 5);
    display(head);
    reverse(head,1,1);
    display(head);
    return 0;
}