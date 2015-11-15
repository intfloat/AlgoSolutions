// RemoveDupFromSortedListII.cpp
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *nx = NULL;
        head = NULL;
        while (cur != NULL) {
            if (cur->next == NULL) {
                if (prev == NULL) {
                    head = cur;
                    return head;
                }
                else {
                    prev->next = cur;
                    return head;
                }
            }
            if (cur->val == cur->next->val) {
                nx = cur->next;
                while (nx!=NULL && nx->val==cur->val) {
                    nx = nx->next;
                }
                if (nx == NULL) {
                    if (prev == NULL) return NULL;
                    prev->next = NULL;
                    return head;
                }
                else {
                    cur = nx;
                }
            }
            // value of current node is not equal to the value
            // of next node
            else {
                // this is the first distinct node
                if (prev == NULL) {                     
                    prev = cur;
                    head = cur;
                    cur = cur->next;
                }
                else {
                    prev->next = cur;
                    prev = cur;
                    cur = cur->next;
                }
            }
        } // end while loop
        return head;        
    } // end method deleteDuplicates
};