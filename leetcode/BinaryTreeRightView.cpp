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
    void dfs(TreeNode* root, int dep) {
        if (root == NULL) return;
        if (res.size() <= dep) res.push_back(root->val);
        else res[dep] = root->val;
        dfs(root->left, dep + 1);
        dfs(root->right, dep + 1);
        return;
    }
    vector<int> rightSideView(TreeNode *root) {
        dfs(root, 0);
        return res;
    }
};
