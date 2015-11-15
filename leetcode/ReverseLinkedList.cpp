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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *prev = NULL, *cur = head, *nt = head->next;
        while (cur != NULL) {
            nt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nt;
        }
        return prev;
    }
};
