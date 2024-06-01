/*
    It's better from single linked list because it allows us to move in both forward and backward directions
*/

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;

    node(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void insert_at_head(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    if(head != NULL){
        head->prev = n;
    }
    head = n;
}

void insert_at_tail(node* &head, int val){

    if(head == NULL){
        insert_at_head(head,val);
        return;
    }

    node* new_node = new node(val);
    node* temp = head;

    while(temp -> next != NULL){
        temp=temp->next;
    }

    temp->next = new_node;
}

void display(node* head){   
    node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp ->next;
    }
    cout << endl;
}

void delete_at_head(node* &head){
    node* to_delete = head;
    head = head -> next;
    head -> prev = NULL;

    delete to_delete;
}

void deletion(node* &head, int pos){
    if(pos == 1){
        delete_at_head(head);
        return; // Exiting early as the head is deleted
    }

    node* temp = head;
    int count = 1; // Start count from 1

    while(temp != NULL && count != pos - 1){ // Correcting the condition
        temp = temp->next;
        count++;
    }

    if(temp == NULL || temp->next == NULL){
        // Handle case where position exceeds the length of the list
        return;
    }

    node* to_delete = temp->next;
    temp->next = to_delete->next;
    
    if(to_delete->next != NULL){
        to_delete->next->prev = temp;
    }

    delete to_delete;
}

int main(){
    node* head = NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    display(head);
    insert_at_head(head,5);
    display(head);
    deletion(head,3);
    display(head);
    return 0;
}