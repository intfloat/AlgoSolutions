// FlattenBinaryTreeToList.cpp

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
    vector<TreeNode*> v;
    void flatten(TreeNode *root) {
        v.clear();
        if(root==NULL) return;
        preorder(root);
        for(int i=0; i<v.size()-1; i++){
            v[i]->left = NULL;
            v[i]->right = v[i+1];
        }
        return;
    }

    void preorder(TreeNode *root){
        if(root == NULL) return;
        v.push_back(root);
        preorder(root->left);
        preorder(root->right);      
    }
};
