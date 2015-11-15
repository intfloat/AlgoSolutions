// SumRootToLeafNumbers.cpp
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
    long long res;
    int sumNumbers(TreeNode *root) {
        res = 0;        
        visit(root, 0);
        return res;
    }

    // I think preorder travesal will work
    void visit(TreeNode *root, long long cur){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            cur = cur*10+root->val;
            res += cur;
            return;
        }
        visit(root->left, cur*10+(root->val));
        visit(root->right, cur*10+(root->val));
        return;
    }// end method visit
};