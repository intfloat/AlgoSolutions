// SortList.cpp

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

    ListNode *merge(ListNode *fir, ListNode *sec){
        ListNode *ptr1 = fir, *ptr2 = sec;
        ListNode *head = NULL;
        if(ptr1==NULL && ptr2==NULL) return head;
        if(ptr1==NULL) return ptr2;
        if(ptr2==NULL) return ptr1;
        if((ptr1->val) <= (ptr2->val))
            head = ptr1;
        else{
            head = ptr2;
            ptr2 = fir;
            ptr1 = sec;
        }
        // ptr1 will point to the smaller value at the
        // beginning of while loop
        while(ptr1!=NULL && ptr2!=NULL){
            ListNode *pre = NULL;
            while((ptr1!=NULL) && (ptr1->val)<=(ptr2->val)){
                pre = ptr1;
                ptr1 = ptr1->next;
            }
            pre->next = ptr2;
            if(ptr1 == NULL) break;
            while((ptr2!=NULL) && (ptr2->val) <= (ptr1->val)){
                pre = ptr2;
                ptr2 = ptr2->next;
            }
            pre->next = ptr1;
        }// end while loop
        return head;
    }

    // merge sort will be reach a complexity of O(NlgN)
    ListNode *sortList(ListNode *head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *slow = head, *fast = head, *prev = NULL;
        // use slow pointer and fast pointer
        // to partition linked list
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // partition the list as evenly as possible
        slow = prev;
        ListNode *fir = head, *sec = slow->next;
        slow->next = NULL;
        fir = sortList(fir);
        sec = sortList(sec);
        head = merge(fir, sec);
        return head;
    }// end method sortList    
};
