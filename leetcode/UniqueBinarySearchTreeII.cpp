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
    vector<TreeNode *> result;
    vector<TreeNode *> generateTrees(int n) {
        result = generate(1, n);
        return result;
    }

    vector<TreeNode*> generate(int left, int right){
        vector<TreeNode*> t;
        t.clear();
        if(left > right){
           t.push_back(NULL);
           return t;
        }
        TreeNode* root = NULL;
        for(int i=left; i<=right; i++){
            vector<TreeNode*> leftVec = generate(left, i-1);
            vector<TreeNode*> rightVec = generate(i+1, right);
            for(int j=0; j<leftVec.size(); j++){
                for(int k=0; k<rightVec.size(); k++){
                    root = new TreeNode(i);
                    root->left = leftVec[j];
                    root->right = rightVec[k];
                    t.push_back(root);
                }
            }
        }
        return t;
    }
};
