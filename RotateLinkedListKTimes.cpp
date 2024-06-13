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

int count_nodes(ListNode* head){
    ListNode* temp = head;
    int cnt = 0;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0){
        return head;
    }
    
    int n = count_nodes(head);
    k = k % n;
    if(k == 0){
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    
    for(int i = 0; i < k; ++i){
        fast = fast->next;
    }
    
    while(fast->next != NULL){              // -->> Here slow moves till "n-k" Node and then don't <<--
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* new_head = slow->next;        // New Head is Slow -> Next's From Test Cases
    slow->next = NULL;
    fast->next = head;
    return new_head;                        // Return The New Head
}

void display(ListNode* head){           // Using by value -> Since we are displaying not modifying
    ListNode* temp = head;
    while(temp != NULL){
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

int main(){
    ListNode* head = NULL;
    int k;  cin>>k;
    insert_at_tail(head, 0);
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    int n = count_nodes(head);
    display(head);
    ListNode* ans = rotateRight(head, k);
    // cout << "s";
    display(ans);
    return 0;
}