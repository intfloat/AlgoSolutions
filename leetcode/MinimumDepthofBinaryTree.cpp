// MinimumDepthofBinaryTree.cpp
#include <limits.h>

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
    int minDepth(TreeNode *root) {
        // this is not a leaf node
        if(root == NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        int res = INT_MAX/2;
        if(root->left!=NULL)
            res = minDepth(root->left)+1;
        if(root->right!=NULL)
            res = min(res, minDepth(root->right)+1);
        return res;
    }
};
