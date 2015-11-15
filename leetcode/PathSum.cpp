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
    int s;
    
    bool check(TreeNode *root, int cur){
        if(root == NULL)
            return (cur==s);
        if((root->left==NULL) && (root->right==NULL))
            return ((cur+root->val)==s);
        else if(root->left==NULL)
            return check(root->right, cur+(root->val));
        else if(root->right==NULL)
            return check(root->left, cur+(root->val));
        else
            return check(root->left, cur+(root->val)) || check(root->right, cur+(root->val));
    }
    
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(root == NULL)
            return false;
        
        s = sum;
        return check(root, 0);
    }
};
