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
    bool isMatch(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL || s->val != t->val) return false;
        return isMatch(s->left, t->left) && isMatch(s->right, t->right);
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool match = isMatch(s, t);
        if (match) return true;
        return (s != NULL) && (isSubtree(s->left, t) || isSubtree(s->right, t));
    }
};