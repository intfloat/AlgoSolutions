// ReverseLinkedListII.cpp
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head==NULL || head->next==NULL) return head;
        if (m == n) return head;
        ListNode *left = NULL, *begin = NULL;
        ListNode *cur = NULL, *prev = NULL, *nx = NULL;
        cur = head;
        // let cur point to first node to reverse
        for (int i=1; i<m; i++) {
            prev = cur;
            cur = cur->next;            
        }       
        left = prev;
        begin = cur;
        prev = cur;
        cur = cur->next;
        nx = cur->next;
        // reverse linked list
        for (int i=m+1; i<=n; i++) {
            cur->next = prev;
            if (i != n){
                prev = cur;
                cur = nx;
                nx = nx->next;
            }
        }
        if (left != NULL) left->next = cur;
        begin->next = nx;
        // determine whether the head node has been changed
        if (m == 1) head = cur;
        return head;
    }
};
