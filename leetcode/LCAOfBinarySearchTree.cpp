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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int v1 = p->val;
        int v2 = q->val;
        if (v1 > v2) {
            swap(v1, v2);
        }
        while (true) {
            if (root->val >= v1 && root->val <= v2) {
                return root;
            }
            else if (root->val < v1) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
    }
};
