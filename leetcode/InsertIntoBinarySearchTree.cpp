/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void solve(TreeNode* root, const int& val) {
        if (val < root->val) {
            if (NULL == root->left) {
                root->left = new TreeNode(val);
            } else {
                solve(root->left, val);
            }
        } else {
            if (NULL == root->right) {
                root->right = new TreeNode(val);
            } else {
                solve(root->right, val);
            }
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (NULL == root) {
            root = new TreeNode(val);
            return root;
        }
        solve(root, val);
        return root;
    }
};
