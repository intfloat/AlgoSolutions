#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int mx_cnt, cur_val, cur_cnt;
    vector<int> res;
    void solve(TreeNode* root) {
        if (NULL == root) {
            return;
        }
        solve(root->left);
        if (root->val == cur_val) {
            ++cur_cnt;
        } else {
            cur_cnt = 1;
        }
        cur_val = root->val;
        if (cur_cnt > mx_cnt) {
            mx_cnt = cur_cnt;
            res.clear();
            res.push_back(root->val);
        } else if (cur_cnt == mx_cnt) {
            res.push_back(root->val);
        }
        solve(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        if (NULL == root) {
            return vector<int>();
        }
        mx_cnt = cur_val = cur_cnt = 0;
        solve(root);
        return res;
    }
};

int main() {
    return 0;
}
