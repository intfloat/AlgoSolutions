// ConstructBinaryTreefromInorderandPostorderTravesal.cpp

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
    vector<int> in, post;
    // inorder travesal is left-root-right
    // postorder travesal is left-right-root
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int len = inorder.size();
        in = inorder; post = postorder;
        TreeNode* root = construct(0, len-1, 0, len-1);
        return root;
    }

    // construct original tree recursively
    TreeNode *construct(int ileft, int iright, int pleft, int pright){
        if(ileft > iright) return NULL;
        TreeNode* root = new TreeNode(post[pright]);
        for(int i=ileft; i<=iright; i++){
            if(in[i]==post[pright]){
                int bound = pleft+(i-ileft)-1;
                root->left = construct(ileft, i-1, pleft, bound);
                root->right = construct(i+1, iright, bound+1, pright-1);
                return root;
            }
        }// end for loop
        // should not reach here
        return NULL;
    }// end method construct
};
