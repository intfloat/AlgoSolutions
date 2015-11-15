// ReverseNodeInKGroup.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // just reverse linked list in k group directly
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head==NULL || head->next==NULL || k==1) return head;
        ListNode *prev = NULL;
        ListNode *nx = NULL;
        ListNode *front = head;
        ListNode *tail = NULL;
        int c = 0;
        while (front != NULL) {
            tail = front;
            c = 0;
            while (c<k && tail!=NULL) {
                c++;
                if (c == k) break;
                tail = tail->next;
            }
            // there is less than k nodes in last group
            if (c < k){             
                return head;
            }
            nx = tail->next;
            // reverse linked nodes in current group
            ListNode *p = front, *cur = front->next;
            ListNode *n = cur->next;
            for (int i=0; i<k-1; i++) {
                cur->next = p;
                p = cur;
                cur = n;
                if (n != NULL) n = n->next;
            }
            // this is the first group
            if (prev == NULL) {
                head = tail;
                front->next = nx;
            }
            else {
                prev->next = tail;
                front->next = nx;
            }
            prev = front;
            front = nx;
        } // end while loop
        return head;
    } // end method reverseKGroup
};

