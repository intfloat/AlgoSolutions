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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *cur, *nex, *nn, *nhead;
        cur = head;
        if(cur==NULL || cur->next==NULL)
            return head;
          
        nhead = cur->next;
        nex = cur->next; nn = nex->next;
        while(true){
            if(nn==NULL || nn->next==NULL)
                cur->next = nn;
            else
                cur->next = nn->next;
            nex->next = cur;
            if(nn==NULL || nn->next==NULL)
                break;
            cur = nn;
            nex = cur->next;
            nn = nex->next;
        }
        return nhead;
    }// end method swapPairs
};
