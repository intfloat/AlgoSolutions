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
    TreeNode* root;
    bool find(TreeNode* root, int rem) {
        if (NULL == root) {
            return false;
        }
        if (root->val == rem) {
            return true;
        } else {
            return find(root->left, rem) || find(root->right, rem);
        }
    }
    int count(TreeNode* root, int v) {
        if (NULL == root) {
            return 0;
        }
        int res = (root->val == v);
        return res + count(root->left, v) + count(root->right, v);
    }
    bool solve(TreeNode* cur, int k) {
        if (cur == NULL) {
            return false;
        }
        int rem = k - cur->val;
        if (rem != cur->val && find(this->root, rem)) {
            return true;
        } else {
            return solve(cur->left, k) || solve(cur->right, k);
        }
    }
public:
    bool findTarget(TreeNode* root, int k) {
        this->root = root;
        // handle duplicate values
        if (k % 2 == 0 && this->count(root, k / 2) >= 2) {
            return true;
        }
        return solve(root, k);
    }
};
