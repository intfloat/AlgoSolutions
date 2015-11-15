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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
          ListNode *pre, *cur, *nhead;
        
        if(head == NULL)
            return head;
        int len = 1;
        cur = head;
        while(cur->next != NULL){
            cur = cur->next;
            len++;
        }
        k = k%len;
        if(k==0)      
            return head;
        k = len-k;
            
        pre=NULL; cur=head;
        for(int i=0; i<k; i++){
            pre = cur;
            cur = cur->next;
        }
        // cur is the new head node
        nhead = cur;
        pre->next = NULL;
        // original tail should point to original head
        while(cur->next != NULL)
            cur = cur->next;
        cur->next = head;
        return nhead;
    }
};
