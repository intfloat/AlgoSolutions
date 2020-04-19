/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avg, sm;
        vector<int> cnt;
        queue<pair<TreeNode*, int> > q;
        q.push({root, 0});
        while (!q.empty()) {
            pair<TreeNode*, int> ptl = q.front();
            q.pop();
            TreeNode* node = ptl.first;
            int level = ptl.second;
            if (level == sm.size()) {
                sm.push_back(0.0);
                cnt.push_back(0);
            }
            sm[level] += node->val;
            ++cnt[level];
            if (NULL != node->left) {
                q.push({node->left, level+1});
            }
            if (NULL != node->right) {
                q.push({node->right, level+1});
            }
        }
        for (int i = 0; i < cnt.size(); ++i) {
            avg.push_back(sm[i] / cnt[i]);
        }
        return avg;
    }
};
