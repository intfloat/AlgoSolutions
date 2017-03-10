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
    int getMinimumDifference(TreeNode* root) {
        this->mn = INT_MAX;
        solve(root);
        return this->mn;
    }

private:
    int mn = INT_MAX;
    pair<int, int> solve(TreeNode* root) {
        pair<int, int> ret;
        if (root->left != NULL) {
            pair<int, int> lp = solve(root->left);
            this->mn = min(this->mn, root->val - lp.second);
            ret.first = lp.first;
        } else {
            ret.first = root->val;
        }
        if (root->right != NULL) {
            pair<int, int> rp = solve(root->right);
            this->mn = min(this->mn, rp.first - root->val);
            ret.second = rp.second;
        } else {
            ret.second = root->val;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    return 0;
}
