/*
    Differences between Linked List and Arrays :-
                i) Array                                        ii) Linked List
            - Can't be Modified Easily                      - Can be modified Easily
           - Continuous Memory Allocation                 - Non continuous Memory Allocation
          - Insertion/Deletion is difficult                 - Insertion/Deletion is Easy
*/

#include<bits/stdc++.h>
using namespace std;

class node{         // Defining a New - Data Type
    public:
    int data;
    node* next;

    node(int val){              // Can be accessed outside class
        data = val;
        next = NULL;
    }
};

void insert_at_tail(node* &head, int val){      // Pass by reference since we want to change the whole Linked-List    
    node* new_node = new node(val);         // Cerating a New Node by dynamic memory allocation
    if(head == NULL){
        head = new_node;
        return;
    }
    
    node* temp = head;

    while(temp->next != NULL){
        temp = temp -> next;
    }
    
    temp->next = new_node;
}

void insert_at_head(node* &head, int val){
    node* new_node = new node(val);
    if(head == NULL){
        head = new_node;
        return;
    }

    new_node -> next = head;            // Making new node point to head
    head = new_node;                    // Making head as NeW_Node
}

void display(node* head){           // Using by value -> Since we are displaying not modifying
    node* temp = head;
    while(temp != NULL){
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

void delete_at_head(node* &head){
    node* to_delete = head;
    head = head -> next;

    delete to_delete;
}

void deletion(node* &head, int val){
    if(head == NULL){
        return;
    }

    if(head -> next == NULL){
        delete_at_head(head);
    }

    node* temp = head;
    while(temp -> next -> data != val){
        temp = temp -> next;        // update
    }
    node* to_delete = temp -> next;
    temp -> next = temp -> next -> next;        //  TEMP KA NEXT POINTER USKE IMMEDIATE NEXT TO LEAVE KARKE AAGE CHALE JAYE
    delete to_delete;
}

bool search(node* head, int key){
    node* temp = head;
    while(temp != NULL){
        if(temp -> data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    node* head = NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    insert_at_head(head,0);
    insert_at_head(head,6);
    display(head);
    cout << search(head,7) << endl;
    cout << search(head,4) << endl;
    deletion(head,5);
    deletion(head,3);
    delete_at_head(head);
    display(head);
    return 0;
}