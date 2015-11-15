// BinaryTreeMaximumPathSum.cpp

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
    int res = INT_MIN/2;
    int maxPathSum(TreeNode *root) {
        if(root == NULL) return 0;
        search(root);
        return res;
    }

    int search(TreeNode *root){
        if(root==NULL) return 0;
        // maximum sum of single chain
        int lsum = search(root->left);
        int rsum = search(root->right);
        // choose maximum child if 
        // at least one of them is positive
        int cur = max(lsum, rsum);
        cur = max(cur, 0)+(root->val);
        int s = root->val;
        if(lsum > 0) s += lsum;
        if(rsum > 0) s += rsum;
        res = max(res, s);
        return cur;
    }
};
