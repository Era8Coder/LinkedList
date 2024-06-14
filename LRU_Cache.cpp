#include <bits/stdc++.h>
using namespace std;

struct node {
    int key;
    int val;
    node* next;
    node* prev;

    node(int _key, int _val) {
        key = _key;
        val = _val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int, node*> cache;
    node* sentinel_head;
    node* sentinel_tail;
    int size;
    int curr_size;

public:
    LRUCache(int capacity) {
        size = capacity;
        curr_size = 0;
        sentinel_head = new node(-1, -1);
        sentinel_tail = new node(-1, -1);
        sentinel_head->next = sentinel_tail;
        sentinel_tail->prev = sentinel_head;
    }

    void insert_at_head(node* node) {
        node->next = sentinel_head->next;
        node->prev = sentinel_head;
        sentinel_head->next->prev = node;
        sentinel_head->next = node;
    }

    void delete_node(node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void move_to_head(node* node) {
        delete_node(node);
        insert_at_head(node);
    }

    void delete_at_tail() {
        node* node = sentinel_tail->prev;
        delete_node(node);
        cache.erase(node->key);
        delete node;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        node* node = cache[key];
        move_to_head(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            node* node = cache[key];
            node->val = value;
            move_to_head(node);
        } else {
            if (curr_size == size) {
                delete_at_tail();
                curr_size--;
            }
            node* new_node = new node(key, value);
            cache[key] = new_node;
            insert_at_head(new_node);
            curr_size++;
        }
    }
};

int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl; // returns 1
    lru.put(3, 3);              // evicts key 2
    cout << lru.get(2) << endl; // returns -1 (not found)
    lru.put(4, 4);              // evicts key 1
    cout << lru.get(1) << endl; // returns -1 (not found)
    cout << lru.get(3) << endl; // returns 3
    cout << lru.get(4) << endl; // returns 4
    return 0;
}
