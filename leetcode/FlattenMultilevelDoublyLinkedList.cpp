#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (NULL == head) {
            return head;
        }
        while (head->prev != NULL) head = head->prev;
        Node* ptr = head;
        while (ptr != NULL) {
            if (ptr->child != NULL) {
                Node* next_level = ptr->child;
                ptr->child = NULL;
                Node* next = ptr->next;
                Node* sub_head = flatten(next_level);
                ptr->next = sub_head;
                sub_head->prev = ptr;
                while (ptr->next != NULL) ptr = ptr->next;
                if (next != NULL) {
                    next->prev = NULL;
                    Node* next_head = flatten(next);
                    ptr->next = next_head;
                    next_head->prev = ptr;
                }
                break;
            } else {
                ptr = ptr->next;
            }
        }
        return head;
    }
};

int main() {
    Solution sol;
    return 0;
}