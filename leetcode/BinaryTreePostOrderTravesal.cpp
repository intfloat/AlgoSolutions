// BinaryTreePostOrderTravesal.cpp
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
    vector<int> postorderTraversal(TreeNode *root) {
        res.clear();
        visit(root);
        return res;
    }

    void visit(TreeNode *root){
        if(root==NULL) return;
        visit(root->left);
        visit(root->right);
        res.push_back(root->val);
        return;
    }
};
