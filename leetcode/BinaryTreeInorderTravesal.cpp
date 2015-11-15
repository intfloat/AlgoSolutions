#include <vector>
using namespace std;

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
    vector<int> result;
    vector<int> inorderTraversal(TreeNode *root) {
        result.clear();
        inorder(root);
        return result;
    }

    void inorder(TreeNode *node){
        if(!node) return;
        inorder(node->left);
        result.push_back(node->val);
        inorder(node->right);
        return;
    }
};

