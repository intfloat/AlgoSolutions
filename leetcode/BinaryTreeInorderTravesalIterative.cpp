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
    vector<TreeNode*> state;
    vector<int> inorderTraversal(TreeNode *root) {
        result.clear(); state.clear();
        TreeNode* node = root;
        // use iterative method
        while(state.size()>0 || node!=NULL){
            if(node != NULL){
                state.push_back(node);
                node = node->left;
            }
            else{
                node = *(state.end()-1);
                state.pop_back();
                result.push_back(node->val);
                node = node->right;
            }
        }
        return result;
    }

};
