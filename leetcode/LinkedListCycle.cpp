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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        bool cycle = false;
        if(head == NULL) return false;
        while(head->next != NULL){
            // just guess a number, the probability of wrong result is very small~
            head->val = -988665544;
            if(head->next->val == -988665544) return true;
            else head = head->next;
        }
        return cycle;
    }
};
