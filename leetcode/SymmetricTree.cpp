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
    bool isSymmetric(TreeNode *root) {
        if(root == NULL) return true;
        return symmetric(root->left, root->right);
    }

    bool symmetric(TreeNode *left, TreeNode *right){
        if(left==NULL && right==NULL) return true;
        if(left==NULL || right==NULL) return false;
        if((left->val) != (right->val)) return false;
        return symmetric(left->right, right->left)
               &&symmetric(left->left, right->right);
    }
};
