
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*, int> > q;
        vector<int> res;
        q.push({root, 0});
        while (!q.empty()) {
            pair<TreeNode*, int> tp = q.front();
            TreeNode* cur = tp.first;
            q.pop();
            if (tp.second >= (int)res.size()) {
                res.push_back(cur->val);
            }
            if (cur->left != NULL) {
                q.push({cur->left, tp.second + 1});
            }
            if (cur->right != NULL) {
                q.push({cur->right, tp.second + 1});
            }
        }
        return res.back();
    }
};
