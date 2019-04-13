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
    private:
    int solve(TreeNode* root, int& res) {
        if (root == NULL) {
            return 0;
        }
        int lsum = solve(root->left, res);
        int rsum = solve(root->right, res);
        res += abs(lsum - rsum);
        return lsum + rsum + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        int ret = 0;
        solve(root, ret);
        return ret;
    }
};