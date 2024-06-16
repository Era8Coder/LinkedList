#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;          // Creating a Min-heap Using greater Function :)
    ListNode* dummy = new ListNode(-1);
    for(int i=0; i<lists.size(); i++){  
        if(lists[i] != NULL)
        {
            pq.push({lists[i]->val, lists[i]});             // -->> Insertion of Pair <<--
        }
    }
    ListNode* temp = dummy;
    while(!pq.empty()){
        pair<int,ListNode*> p = pq.top();
        temp -> next = p.second;
        pq.pop();
        if(p.second -> next != NULL){
            pq.push({p.second->next->val, p.second->next});                 // Pritority Queue which stores the Pairs :)          
        }
        temp = temp -> next;
    }
    return dummy -> next;
}

ListNode* main(){
    vector<ListNode*> lists;
    return mergeKLists(lists);              // Time Complexity -> O(N*K*log(K)) -->> Most Beautiful Time Complexity As Her :)
}