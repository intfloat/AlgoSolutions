#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        queue<pair<TreeNode*, int> > q;
        q.push({root, 0});
        while (!q.empty()) {
            pair<TreeNode*, int> tp = q.front();
            TreeNode* ptr = tp.first;
            int depth = tp.second;
            q.pop();
            if (ptr != NULL) {
                if (depth >= (int)res.size()) {
                    res.push_back(ptr->val);
                } else {
                    res[depth] = max(res[depth], ptr->val);
                }
                q.push({ptr->left, depth + 1});
                q.push({ptr->right, depth + 1});
            }
        }
        return res;
    }
};

int main() {
    return 0;
}