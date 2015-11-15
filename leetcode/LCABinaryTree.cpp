/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool ok;
TreeNode *n1, *n2, *res;
class Solution {
private:
    int dfs(TreeNode* root) {
        if (ok || root == NULL) {
            return 0;
        }
        int ret = (root == n1);
        ret += (root == n2);
        ret += dfs(root->left);
        ret += dfs(root->right);
        if (!ok && ret == 2) {
            ok = true;
            res = root;
        }
        return ret;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ok = false;
        n1 = p;
        n2 = q;
        dfs(root);
        return res;
    }
};
