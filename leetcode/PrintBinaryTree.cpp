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
    vector<vector<string>> res;
    int get_depth(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        return max(get_depth(root->left), get_depth(root->right)) + 1;
    }
    void solve(TreeNode* root, int r, int left, int right) {
        if (NULL == root) {
            return;
        }
        int c = (left + right) / 2;
        this->res[r][c] = to_string(root->val);
        solve(root->left, r + 1, left, c - 1);
        solve(root->right, r + 1, c + 1, right);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        this->res.clear();
        int depth = get_depth(root);
        int width = (1 << depth) - 1;
        for (int i = 0; i < depth; ++i) {
            this->res.push_back(vector<string>(width, ""));
        }
        solve(root, 0, 0, width - 1);
        return this->res;
    }
};
