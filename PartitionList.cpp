#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void display(ListNode* head){
    ListNode* temp = head;
    while(temp != NULL){
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}   

ListNode* partition(ListNode* head, int x){
    ListNode* small = new ListNode(0);
    ListNode* large = new ListNode(0);

    ListNode* temp = head;
    ListNode* temp1= small;
    ListNode* temp2= large;

    while(temp != NULL){
        if(temp->val < x){
            temp1 -> next = new ListNode(temp -> val);
            temp1 = temp1 -> next;
        }
        if(temp->val >= x){
            temp2 -> next = new ListNode(temp -> val);
            temp2 = temp2 -> next;
        }
        temp = temp -> next;
    }
    temp2->next=NULL;
    temp1->next = large -> next;
    /* Below is the Good practive of freeing the Dummy Node -->> */
    ListNode* new_head = small->next;
    delete small;
    delete large;
    
    return new_head;
    // return small -> next;
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

int main(){
    ListNode* head = new ListNode(1);
    insert_at_tail(head,4);
    insert_at_tail(head,3);
    insert_at_tail(head,2);
    insert_at_tail(head,5);
    insert_at_tail(head,2);
    display(head);
    cout << "Hello" << endl;
    display(partition(head, 3));
    return 0;
}