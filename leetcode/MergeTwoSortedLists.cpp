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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p1, *p2, *head, *cur;
        if(l1 == NULL)      
            return l2;
        if(l2 == NULL)
            return l1;
        
        p1=l1; p2=l2;
        if(l1->val < l2->val){
            head = new ListNode(l1->val);
            p1 = l1->next;
        }
        else{
            head = new ListNode(l2->val);
            p2 = l2->next;
        }
        cur = head;
        while(true){
            if(p1==NULL && p2==NULL)
                break;
            if(p1==NULL && p2!=NULL){
                while(p2!=NULL){
                    cur->next = new ListNode(p2->val);
                    p2 = p2->next;
                    cur = cur->next;
                }
                return head;
            }
            else if(p1!=NULL && p2==NULL){
                while(p1!=NULL){
                    cur->next = new ListNode(p1->val);
                    p1 = p1->next;
                    cur = cur->next;
                }
                return head;
            }
            else if(p1->val < p2->val){
                cur->next = new ListNode(p1->val);
                cur = cur->next;
                p1 = p1->next;
            }
            else{
                cur->next = new ListNode(p2->val);
                cur = cur->next;
                p2 = p2->next;
            }
        }// end while loop
        
        return head;
    }
};
