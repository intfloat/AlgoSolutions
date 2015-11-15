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
    
    int s;
    vector<vector<int> > res;
    
    void travel(TreeNode *root, int cur, vector<int> record){
        
        // it is a leaf node
        if((root->left==NULL) && (root->right==NULL)){          
            if((cur+(root->val)) == s){
                vector<int> v = record;
                v.push_back(root->val);
                res.push_back(v);
            }
            return;
        }
        
        // traverse on the left subtree
        if(root->left != NULL){
            vector<int> v = record;
            v.push_back(root->val);
            travel(root->left, cur+(root->val), v);
        }
        
        // travese on the right subtree
        if(root->right != NULL){
            vector<int> v = record;
            v.push_back(root->val);
            travel(root->right, cur+(root->val), v);
        }
        
        return;
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        s = sum;
        res.clear();
        vector<int> record;
        record.clear();
        if(root == NULL)
            return res;
        
        travel(root, 0, record);
        
        return res;
    }
};
