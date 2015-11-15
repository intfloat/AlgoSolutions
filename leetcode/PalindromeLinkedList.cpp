// struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
// };
class Solution {
private:
    void reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        ListNode *pv = NULL, *cur = head, *nt = head->next;
        while (true) {
            cur->next = pv;
            pv = cur;
            cur = nt;
            if (cur == NULL) {
                return;
            }
            nt = nt->next;
        }
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        int sz = 1;
        ListNode *ptr = head, *pv;
        while (ptr->next != NULL) {
            ++sz;
            ptr = ptr->next;
        }
        ptr = head;
        for (int i = 0; i < sz / 2; ++i) {
            pv = ptr;
            ptr = ptr->next;
        }
        if (sz % 2) {
            ptr = ptr->next;
        }
        pv->next = NULL;
        // reverse first half of linked list
        reverseList(head);
        ListNode* nhead = pv;
        // check if it is a valid palindrome
        for (int i = 0; i < sz / 2; ++i) {
            if (ptr->val != nhead->val) {
                return false;
            }
            else {
                ptr = ptr->next;
                nhead = nhead->next;
            }
        }
        return true;
    }
};
