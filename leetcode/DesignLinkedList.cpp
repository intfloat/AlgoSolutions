#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(NULL) {}
};

class MyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = tail = NULL;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0) return -1;

        Node* ptr = head;
        for (int i = 0; i < index && ptr != NULL; ++i) {
            ptr = ptr->next;
        }
        return ptr == NULL ? -1 : ptr->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            Node* nhead = new Node(val);
            nhead->next = head;
            head = nhead;
        }
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (tail == NULL) {
            tail = new Node(val);
            head = tail;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* ptr = head;
        for (int i = 0; i < index - 1; ++i) {
            if (ptr == NULL || ptr->next == NULL) {
                return;
            }
            ptr = ptr->next;
        }
        Node* node = new Node(val);
        node->next = ptr->next;
        ptr->next = node;
        if (node->next == NULL) {
            tail = node;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0) return;
        if (index == 0 && head != NULL) {
            head = head->next;
            if (head == NULL) {
                tail = NULL;
            }
            return;
        }

        Node* ptr = head;
        Node* last = NULL;
        for (int i = 0; i < index; ++i) {
            if (ptr == NULL || ptr->next == NULL) {
                return;
            }
            last = ptr;
            ptr = ptr->next;
        }
        last->next = ptr->next;
        if (last->next == NULL) {
            tail = last;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
    int index = 0;
    int val = 23;
    MyLinkedList* obj = new MyLinkedList();
    int param_1 = obj->get(index);
    obj->addAtHead(val);
    obj->addAtTail(val);
    obj->addAtIndex(index,val);
    obj->deleteAtIndex(index);
    return 0;
}
