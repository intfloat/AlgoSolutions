//BinaryTreeZigzagLevelTravelsal.cpp

#include <queue>
#include <vector>
#include <utility>
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
    // perform regular tree level travesal, then reverse some of them
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        res.clear();
        if(root == NULL) return res;
        queue<pair<TreeNode*, int> > q;
        while(q.empty()==false) q.pop();
        q.push(make_pair(root, 0));

        // iterative method
        vector<int> v = vector<int>(10);
        while(q.empty() == false){
            pair<TreeNode*, int> cur = q.front();
            q.pop();
            if(cur.first == NULL) continue;
            while((res.size()) < cur.second+1){
                v.clear();
                res.push_back(vector<int>());
            }
            res[cur.second].push_back((cur.first)->val);
            q.push(make_pair((cur.first)->left, (cur.second)+1));
            q.push(make_pair((cur.first)->right, (cur.second)+1));
        }// end while loop

        for(int i=1; i<res.size(); i+=2)
            reverse(res[i].begin(), res[i].end());
        return res;
    }
};
