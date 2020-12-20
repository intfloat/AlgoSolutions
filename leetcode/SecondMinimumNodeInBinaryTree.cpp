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
    set<int> s;
    void dfs(TreeNode* root) {
        if (NULL == root) {
            return;
        } else {
            this->s.insert(root->val);
            dfs(root->left);
            dfs(root->right);
        }
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL || root->left == NULL) {
            return -1;
        }
        s.clear();
        dfs(root);
        if (s.size() < 2) {
            return -1;
        }
        auto it = s.begin();
        ++it;
        return *it;
    }
};
