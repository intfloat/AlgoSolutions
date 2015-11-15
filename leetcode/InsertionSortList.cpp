// InsertionSortList.cpp

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
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *cur = head->next, *parent = NULL;
        // visit every node in the linked list sequentially
        while(cur != NULL){
            ListNode *pos = head, *prev = NULL;
            while(pos!=cur && (pos->val)<(cur->val) ){
                prev = pos;
                pos = pos->next;
            }
            ListNode *ncur = cur->next;
            // current node has largest value
            if(pos == cur){
                cur = ncur;
                continue;
            }           
            if(prev != NULL) prev->next = cur;
            // current node has smallest value
            else head = cur;
            cur->next = pos;
            parent = pos;
            // change last pointer to avoid cycle in linked list
            while(parent!=NULL && parent->next != cur){
                parent = parent->next;              
            }
            if(parent != NULL)
                parent->next = ncur;
            cur = ncur;
        }
        return head;
    }// end method insertionSortList
};