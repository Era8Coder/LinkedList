#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    // Check if there are at least k nodes left to reverse
    int countNodes = 0;
    ListNode* temp = head;
    while (temp != NULL && countNodes < k) {
        temp = temp->next;
        countNodes++;
    }
    
    // If we have less than k nodes, return the head without reversing
    if (countNodes < k) {
        return head;
    }

    // Step-1 : Reverse first k nodes
    ListNode* next = NULL;
    ListNode* curr = head;
    ListNode* prev = NULL;
    int cnt = 0;

    while(curr != NULL && cnt < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    // Recursively call for the next groups
    if (next != NULL){
        head->next = reverseKGroup(next, k);
    }

    // Return the head of the reversed list
    return prev;
}

void display(ListNode* head){
    ListNode* temp = head;
    while(temp != NULL){
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}   

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    display(head);

    int k = 3;
    head = reverseKGroup(head, k); // Correctly assign the result of reverseKGroup to head

    display(head);
    return 0;
}
