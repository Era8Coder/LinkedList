#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        // Step - 1: Copy all the Nodes and Insert them between the Nodes
        Node* curr = head;
        while (curr != NULL) {
            Node* n = new Node(curr->val);
            n->next = curr->next;
            curr->next = n;
            curr = n->next;
        }

        // Step - 2: Copy random pointers
        curr = head;
        while (curr != NULL) {
            if (curr->random)
                curr->next->random = curr->random->next; // Taking care of NULL random pointers
            curr = curr->next->next;
        }

        // Step - 3: Separate the two lists
        Node* new_head = head->next;
        Node* original = head;
        Node* copy = new_head;
        while (original != NULL) {
            original->next = copy->next;
            original = original->next;
            if (original != NULL) {
                copy->next = original->next;
                copy = copy->next;
            }
        }

        return new_head;
    }
};
