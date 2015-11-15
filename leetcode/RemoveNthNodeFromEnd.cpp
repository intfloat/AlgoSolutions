/**struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};**/

 
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int total = 0;
       ListNode *pre, *cur;
     cur = head;
       
       total++;
       while(cur->next != NULL){
            cur = cur->next;
            total++;
       }
       
       int number = total+1-n;
       int order = number;
       pre=NULL; cur=head;
       while(number > 1){
            number--;
            pre = cur;
            cur = cur->next;    
       }
       
       // delete the head element
       if(order == 1)
            head = head->next;
        // delete the last element
        else if(order == total)
            pre->next = NULL;   
        // otherwise        
        else
            pre->next = cur->next;
        return head;
    }
};
