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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(lists.size()==0)
            return NULL;
        
        vector<int> v;
        ListNode *cur, *res, *head;
        v.clear();
        for(int i=0; i<lists.size(); i++){
        cur = lists[i];
            while(cur != NULL){
                v.push_back(cur->val);
                cur = cur->next;
            }
        }// end for loop
        
        if(v.size()==0)
            return NULL;
        
        sort(v.begin(), v.end());
        res = new ListNode(v[0]); 
        head = res;
        for(int i=1; i<v.size(); i++){
            res->next = new ListNode(v[i]);
            res = res->next;
        }
        return head;
    }
};
