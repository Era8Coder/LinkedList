#include<bits/stdc++.h>
using namespace std;

class ListNode{         // Defining a New - Data Type
    public:
    int data;
    ListNode* next;

    ListNode(int val){              // Can be accessed outside class
        data = val;
        next = NULL;
    }
};

void insert_at_tail(ListNode* &head, int val){      // Pass by reference since we want to change the whole Linked-List    
    ListNode* new_node = new ListNode(val);         // Cerating a New Node by dynamic memory allocation
    if(head == NULL){
        head = new_node;
        return;
    }
    
    ListNode* temp = head;

    while(temp->next != NULL){
        temp = temp -> next;
    }
    
    temp->next = new_node;
}

void display(ListNode* head){           // Using by value -> Since we are displaying not modifying
    ListNode* temp = head;
    while(temp != NULL){
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

ListNode* remove_duplicates(ListNode* &head){
    ListNode* dummy = new ListNode(0); 
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* curr = head;
    while(curr != NULL){
        if(curr->next != NULL && curr->data == curr->next->data){
            // Skip the nodes whose values are equal to head
            while(curr->next != NULL && curr->data == curr->next->data){
                curr = curr -> next;
            }
            prev->next = curr->next;
        }else{
            prev = prev -> next;
        }
        curr = curr->next;
    }
    return dummy->next;
}

int main(){
    ListNode* head = NULL;
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 4);
    // insert_at_tail(head, 1);
    // cout << "s";
    ListNode* ans = remove_duplicates(head);
    display(ans);
    return 0;
}