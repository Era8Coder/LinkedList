#include<bits/stdc++.h>
using namespace std;

struct node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

node* sort_list(node* head, vector<int> &v){
    node* temp = head;
    while(temp != NULL){
        v.push_back(temp -> data);
        temp = temp -> next;
    }
    sort(v.begin(),v.end());

    node* temp1 = head;
    int cnt = 0;
    while(temp1 != NULL){
        temp1->data = v[cnt];
        cnt++;
        temp1 = temp1 -> next; 
    }
    
    return head;
}

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

void display(node* head){           // Using by value -> Since we are displaying not modifying
    node* temp = head;
    while(temp != NULL){
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

int main(){
    node* head = NULL;
    insert_at_tail(head,4);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,7);
    insert_at_tail(head,5);
    vector<int> v;
    display(head);
    sort_list(head, v);
    display(head);
    return 0;
}