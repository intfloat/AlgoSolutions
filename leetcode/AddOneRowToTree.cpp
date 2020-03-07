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
    TreeNode* solve(TreeNode* root, int v, int d, int cur_d) {
        if (root == NULL) {
            return NULL;
        }
        if (cur_d == d - 1) {
            TreeNode* new_left = new TreeNode(v);
            new_left->left = root->left;
            TreeNode* new_right = new TreeNode(v);
            new_right->right = root->right;
            root->left = new_left;
            root->right = new_right;
            return root;
        } else {
            solve(root->left, v, d, cur_d + 1);
            solve(root->right, v, d, cur_d + 1);
            return root;
        }
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* new_root = new TreeNode(v);
            new_root->left = root;
            return new_root;
        }
        return solve(root, v, d, 1);
    }
};
