/*
    Focus is your utmost priority :)
*/

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

node* reverse(node* &head){
    node* prev_ptr = NULL;
    node* curr_ptr = head;
    node* next_ptr = NULL;

    while(curr_ptr != NULL){
        next_ptr = curr_ptr -> next;
        curr_ptr -> next = prev_ptr;
        prev_ptr = curr_ptr;
        curr_ptr = next_ptr;
    }

    head = prev_ptr;                // Pointer from Backward Direction -> That is we are going to return a reversed Linked List
    return head;
}

int main(){
    node* head = NULL;
    insert_tail(head, 1);
    insert_tail(head, 2);
    insert_tail(head, 3);
    insert_tail(head, 4);
    insert_tail(head, 5);
    display(head);
    node* k = reverse(head);
    display(k);
    return 0;
}