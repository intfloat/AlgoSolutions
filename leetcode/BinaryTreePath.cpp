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
    string int_to_str(int num) {
        stringstream ss;
        string ret;
        ss << num;
        ss >> ret;
        return ret;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (NULL == root) {
            return res;
        }
        string v = int_to_str(root->val);
        if (NULL == root->left && NULL == root->right) {
            res.push_back(v);
            return res;
        }
        if (NULL != root->left) {
            vector<string> t = binaryTreePaths(root->left);
            for (int i = 0; i < t.size(); ++i) {
                res.push_back(v + "->" + t[i]);
            }
        }
        if (NULL != root->right) {
            vector<string> t = binaryTreePaths(root->right);
            for (int i = 0; i < t.size(); ++i) {
                res.push_back(v + "->" + t[i]);
            }
        }
        return res;
    }
};
