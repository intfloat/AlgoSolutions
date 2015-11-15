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
    vector<vector<int> > levelOrder(TreeNode *root) {
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
            // cout<<"second: "<<cur.second<<endl;
            // cout<<"s: "<<res.size()<<endl;
            // cout<<"size: "<<(res.size()-1)<<endl;
            while((res.size()) < cur.second+1){
                // cout<<"haha"<<endl;
                v.clear();
                // cout<<"before"<<endl;
                res.push_back(vector<int>());
                // cout<<"push"<<endl;
            }
            // cout<<"here: "<<res.size()<<endl;
            res[cur.second].push_back((cur.first)->val);
            // cout<<"flag1"<<endl;
            q.push(make_pair((cur.first)->left, (cur.second)+1));
            q.push(make_pair((cur.first)->right, (cur.second)+1));
        }// end while loop

        return res;
    }
};
