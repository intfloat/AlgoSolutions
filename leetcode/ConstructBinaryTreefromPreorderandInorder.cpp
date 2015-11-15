// ConstructBinaryTreefromPreorderandInorder.cpp

#include <vector>

using namespace std;

 
class Solution {
public:
    vector<int> pre, in;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        pre = preorder; in = inorder;
        int len = pre.size();
        TreeNode *root = construct(0, len-1, 0, len-1);
        return root;
    }

    // construct original tree recursively
    TreeNode *construct(int pleft, int pright, int ileft, int iright){
        if(pleft > pright) return NULL;
        TreeNode *root = new TreeNode(pre[pleft]);
        // find the boundary
        for(int i=ileft; i<=iright; i++){
            if(in[i]==pre[pleft]){
                int low = i-ileft;
                root->left = construct(pleft+1, pleft+low, ileft, i-1);
                root->right = construct(pleft+low+1, pright, i+1, iright);
                return root;
            }// end if
        }// end for loop
        // this line should not be executed
        return root;
    }
};

