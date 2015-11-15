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
    bool isValidBST(TreeNode *root) {
        if(root == NULL) return true;
        bool result = validate(root->left, INT_MIN, root->val) 
            && validate(root->right, root->val, INT_MAX);
    }

    bool validate(TreeNode *root, int low, int upp){
        if(root == NULL) return true;
        if((root->val)<=low || (root->val)>=upp) return false;
        return validate(root->left, low, root->val)
                 && validate(root->right, root->val, upp);
    }
};

