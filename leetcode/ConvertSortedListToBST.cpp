// ConvertSortedListToBST.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    std::vector<int> v;
    // copy all elements into a vector,
    // then it will support random access
    TreeNode *sortedListToBST(ListNode *head) {
        v.clear();
        ListNode *cur = head;
        while(cur != NULL){
            v.push_back(cur->val);
            cur = cur->next;
        }
        int len = v.size();
        return construct(0, len-1);
    }

    // construct original tree recursively
    TreeNode *construct(int begin, int end){
        if(begin > end) return NULL;
        int middle = (begin+end)/2;
        TreeNode *root = new TreeNode(v[middle]);
        root->left = construct(begin, middle-1);
        root->right = construct(middle+1, end);
        return root;
    }// end method construct

};

