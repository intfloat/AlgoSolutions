#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int val;
    Node* next;
    Node(int k, int v): key(k), val(v), next(NULL) {}
};

class MyHashMap {
private:
    vector<Node*> table;
    int get_hash(int key) {
        int ret = key % table.size();
        if (ret < 0) {
            return ret + table.size();
        } else {
            return ret;
        }
    }
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        table.resize(9997);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int h = get_hash(key);
        Node* ptr = table[h];
        if (ptr == NULL) {
            table[h] = new Node(key, value);
            return;
        }
        Node* last = NULL;
        while (ptr != NULL) {
            if (ptr->key == key) {
                ptr->val = value;
                return;
            }
            last = ptr;
            ptr = ptr->next;
        }
        last->next = new Node(key, value);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int h = get_hash(key);
        Node* ptr = table[h];
        while (ptr != NULL) {
            if (ptr->key == key) return ptr->val;
            ptr = ptr->next;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if (get(key) == -1) return;

        int h = get_hash(key);
        Node* ptr = table[h];
        if (ptr->key == key) {
            table[h] = ptr->next;
            return;
        }
        Node* last = NULL;
        while (ptr != NULL) {
            if (ptr->key == key) {
                last->next = ptr->next;
                return;
            }
            last = ptr;
            ptr = ptr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
    MyHashMap solution;
    return 0;
}
