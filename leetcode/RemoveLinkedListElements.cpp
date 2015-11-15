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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return NULL;
        ListNode *prev = NULL, *nhead = NULL, *cur = head;
        while (cur != NULL) {
            if (cur->val == val) {
                if (prev != NULL) prev->next = cur->next;
                cur = cur->next;
            }
            else {
                if (nhead == NULL) nhead = cur;
                prev = cur;
                cur = cur->next;
            }
        }
        return nhead;
    }
};
