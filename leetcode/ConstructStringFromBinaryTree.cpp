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
    string tree2str(TreeNode* t) {
        string res;
        if (NULL == t) {
            return res;
        }
        res += to_string(t->val);
        if (t->left == NULL && t->right == NULL) {
            return res;
        } else if (t->left != NULL && t->right == NULL) {
            res += "(";
            res += tree2str(t->left);
            res.push_back(')');
            return res;
        } else if (t->left == NULL && t->right != NULL) {
            res += "()(";
            res += tree2str(t->right);
            res += ")";
            return res;
        } else {
            res.push_back('(');
            res += tree2str(t->left);
            res += ")(";
            res += tree2str(t->right);
            res.push_back(')');
            return res;
        }
    }
};
