// BinaryTreePreorderTravesal.cpp
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
    vector<int> res;
    // I think recursion is much more cleaner and easier to implement
    vector<int> preorderTraversal(TreeNode *root) {
        res.clear();
        visit(root);
        return res;
    }

    void visit(TreeNode *root){
        if(root==NULL) return;
        res.push_back(root->val);
        visit(root->left);
        visit(root->right);
        return;
    }
};
