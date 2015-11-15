// LRUCache.cpp

#include <map>
#include <iterator>
#include <iostream>
#include <cassert>

using namespace std;

struct MyNode{
    int val;
    int node_key;
    MyNode *pre, *next;
    MyNode(int x) : val(x), pre(NULL), next(NULL), node_key(0) {}
    MyNode(int x, int k) : val(x), pre(NULL), next(NULL), node_key(k) {}
};

// implement both O(1) set algorithm and O(1) get algorithm
// using bidirectionl linked list
class LRUCache{
public:
    int cap;
    map<int, MyNode*> m;
    MyNode *head, *tail;
    map<int, MyNode*>::iterator it;

    void adjust(MyNode *cur){
        if(cur==tail) return;
        if(cur==head){
            head = cur->next;
            head->pre = NULL;
            cur->next = NULL;
            cur->pre = tail;
            tail->next = cur;
            tail = cur;
        }
        else{
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
            tail->next = cur;
            cur->next = NULL;
            cur->pre = tail;
            tail = cur;
        }
        return;
    }

    LRUCache(int capacity) {
        cap = capacity;
        m.clear();
        head = NULL;
        tail = NULL;
    }// end constructor
    
    int get(int key) {      
        it = m.find(key);
        if(it==m.end()) return -1;
        MyNode *cur = m[key];
        int res = cur->val;
        // need to adjust the order of linked list
        // as this node is visited
        adjust(cur);
        return res;
    }// end method get
    
    void set(int key, int value) {
        if(cap == 0) return;
        it = m.find(key);
        if(it==m.end()){
            MyNode *node = new MyNode(value, key);
            // this is the first node
            if(tail==NULL){
                head = node;
                tail = node;
            }
            else{
                node->pre = tail;
                tail->next = node;
                tail = node;
            }
            m[key] = node;
            // need to delete the head node
            if(m.size() > cap){
                MyNode *tmp = head;
                head = head->next;
                head->pre = NULL;
                it = m.find(tmp->node_key);
                assert(it!=m.end());
                m.erase(it);
                delete tmp;
            }
            return;
        }// end external if clause
        // it already exists
        MyNode *cur = m[key];
        cur->val = value;
        adjust(cur);
        return;
    }// end method set

};
