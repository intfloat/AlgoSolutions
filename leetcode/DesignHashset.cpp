#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(NULL) {}
};

class MyHashSet {
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
    MyHashSet() {
        table.resize(9997);
    }

    void add(int key) {
        if (contains(key)) {
            return;
        }

        int h = get_hash(key);
        Node* ptr = table[h];
        if (ptr == NULL) {
            table[h] = new Node(key);
            return;
        }
        while (ptr->next != NULL) ptr = ptr->next;
        ptr->next = new Node(key);
    }

    void remove(int key) {
        if (!contains(key)) {
            return;
        }

        int h = get_hash(key);
        Node* prev = table[h];
        if (prev->val == key) {
            table[h] = prev->next;
            return;
        }
        Node* ptr = prev->next;
        while (ptr->val != key) {
            ptr = ptr->next;
            prev = prev->next;
        }
        prev->next = ptr->next;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int h = get_hash(key);
        Node* ptr = table[h];
        while (ptr != NULL) {
            if (ptr->val == key) return true;
            ptr = ptr->next;
        }
        return false;
    }
};

int main() {
    Solution solution;
    return 0;
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
