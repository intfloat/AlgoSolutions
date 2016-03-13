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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *odd = head, *even = head->next;
        ListNode *odd_tail = odd, even_tail = even;
        while (true) {
            if (even_tail->next == NULL) {
                odd_tail->next = even;
                return odd;
            }
            else if (even_tail->next->next == NULL) {
                odd_tail->next = even_tail->next;
                odd_tail = odd_tail->next;
                odd_tail->next = even;
                even_tail->next = NULL;
                return odd;
            }
            else {
                odd_tail->next = even_tail->next;
                odd_tail = odd_tail->next;
                even_tail->next = odd_tail->next;
                even_tail = even_tail->next;
            }
        }
    }
};
