/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 typedef pair<int, int> pii;
class Solution {
private:
    pii solve(TreeNode* root) {
        if (root == NULL) {
            return make_pair(0, 0);
        }
        pii l = solve(root->left);
        pii r = solve(root->right);
        int d1 = root->val + l.first + r.first;
        int d2 = max(d1, l.second + r.second);
        return make_pair(l.second + r.second, d2);
    }
public:
    int rob(TreeNode* root) {
        pii res = solve(root);
        return max(res.first, res.second);
    }
};
