#include <bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = this->getLength(l1);
        int len2 = this->getLength(l2);
        if (len1 < len2) {
            swap(l1, l2);
            swap(len1, len2);
        }
        vector<int> res;
        ListNode *ptr1 = l1, *ptr2 = l2;
        for (int i = 0; i < len1 - len2; ++i) {
            res.push_back(ptr1->val);
            ptr1 = ptr1->next;
        }
        for (int i = 0; i < len2; ++i) {
            res.push_back(ptr1->val + ptr2->val);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        reverse(res.begin(), res.end());
        int carry = 0;
        for (int i = 0; i < (int)res.size(); ++i) {
            res[i] += carry;
            carry = res[i] / 10;
            res[i] %= 10;
        }
        if (carry > 0) {
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());
        return this->constructList(res);
    }
private:
    int getLength(ListNode* l) const {
        int ret = 0;
        while (l != NULL) {
            ++ret;
            l = l->next;
        }
        return ret;
    }
    ListNode* constructList(const vector<int>& digits) const {
        ListNode *head = new ListNode(digits[0]);
        ListNode *ptr = head;
        for (int i = 1; i < (int)digits.size(); ++i) {
            ptr->next = new ListNode(digits[i]);
            ptr = ptr->next;
        }
        return head;
    }
};

int main() {
    Solution sol;
    return 0;
}
