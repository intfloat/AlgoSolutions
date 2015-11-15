// ConvertSortedArrayToBST.cpp
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
    // easy stuff
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int len = num.size();           
        if(len == 0) return NULL;
        v = num;
        TreeNode* root = new TreeNode(num[len/2]);
        root->left = construct(0, len/2-1);
        root->right = construct(len/2+1, len-1);
        return root;
    }// end method sortedArrayToBST

    // construct original tree recursively
    TreeNode *construct(int begin, int end){
        if(begin > end) return NULL;
        int middle = (begin+end)/2;
        TreeNode* root = new TreeNode(v[middle]);
        root->left = construct(begin, middle-1);
        root->right = construct(middle+1, end);
        return root;
    }// end method construct
};
