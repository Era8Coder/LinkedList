// Method for Finding the Cycle in a Linked List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){           // Both must be satisfied at the same time to ensure the cycle 
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                return true;        // Cycle Exists
            }
        }

        return false;
    }
};
*/