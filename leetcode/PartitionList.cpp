// PartitionList.cpp
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
    ListNode *partition(ListNode *head, int x) {
        if (head==NULL || head->next==NULL) return head;
        ListNode *small = NULL, *large = NULL;
        ListNode *stail = NULL, *ltail = NULL;
        ListNode *cur = head;
        while (cur != NULL) {
            if (cur->val < x) {
                if (small == NULL){
                    small = cur;
                    stail = cur;
                }
                else {
                    stail->next = cur;
                    stail = stail->next;
                }
            }
            else {
                if (large == NULL) {
                    large = cur;
                    ltail = cur;
                }
                else {
                    ltail->next = cur;
                    ltail = ltail->next;
                }
            } // end else
            // update current pointer
            cur = cur->next;
        }
        if (small != NULL) {
            stail->next = large;
            if (ltail != NULL)
                ltail->next = NULL;
            head = small;
        }
        // all numbers are greater than or equal to x
        else {
            head = large;
            ltail->next = NULL;
        }
        return head;
    }
};