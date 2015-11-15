// BalancedBinaryTree.cpp
#include <algorithm>
#include <cmath>

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
    bool isBalanced(TreeNode *root) {
        if(root == NULL) return true;
        bool res = isBalanced(root->left)&&isBalanced(root->right);
        if(res==false) return res;
        int h1 = getHeight(root->left);
        int h2 = getHeight(root->right);
        if(abs(h1-h2) > 1)
            return false;
        return true;
    }

    // using dynamic programming can avoid repeated computing,
    // but I think this is clean and fast enough
    int getHeight(TreeNode *root){
        if(root == NULL) return 0;
        return max(getHeight(root->left), getHeight(root->right))+1;
    }
};
