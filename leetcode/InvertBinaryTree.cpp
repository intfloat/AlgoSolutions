/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tp = q.front(); q.pop();
            swap(tp->left, tp->right);
            if (tp->left != NULL) q.push(tp->left);
            if (tp->right != NULL) q.push(tp->right);
        }
        return root;
    }
};
