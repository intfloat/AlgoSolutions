// ReorderList.cpp
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
    void reorderList(ListNode *head) {
        if(head==NULL) return;
        vector<ListNode *> v, res;
        v.clear(); res.clear();
        ListNode *cur = head;
        while(cur!=NULL){
            v.push_back(cur);
            cur = cur->next;
        }
        int left = 0;
        int right = v.size()-1;
        // cost some extra memory but easier to implement
        while(left < right){
            res.push_back(v[left]);
            res.push_back(v[right]);
            left++; right--;
        }
        // avoid push back the node right in the middle multiple times
        if(left==right) res.push_back(v[left]);
        int len = res.size();
        for(int i=0; i<len-1; i++){
            res[i]->next = res[i+1];
        }
        res[len-1]->next = NULL;
        return;
    }
};