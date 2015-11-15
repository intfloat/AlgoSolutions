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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        int cntA = 0, cntB = 0;
        ListNode *ptrA = headA, *ptrB = headB;
        while (ptrA->next != NULL) {
            ++cntA; ptrA = ptrA->next;
        }
        while (ptrB->next != NULL) {
            ++cntB; ptrB = ptrB->next;
        }
        if (ptrA != ptrB) return NULL;
        ptrA = headA; ptrB = headB;
        if (cntA < cntB) { swap(cntA, cntB); swap(ptrA, ptrB); }
        for (int i = 0; i < cntA - cntB; ++i) {
            ptrA = ptrA->next;
        }
        while (ptrA != ptrB) {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        return ptrA;
    }
};
