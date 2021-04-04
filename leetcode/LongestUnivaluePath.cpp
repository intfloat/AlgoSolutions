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
    int res;
    int dfs(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        int cur_depth = 0, cur_res = 0;
        if (root->left != NULL && root->left->val == root->val) {
            cur_res += left + 1;
            cur_depth = max(cur_depth, left + 1);
        }
        if (root->right != NULL && root->right->val == root->val) {
            cur_res += right + 1;
            cur_depth = max(cur_depth, right + 1);
        }
        res = max(res, cur_res);
        return cur_depth;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
};
