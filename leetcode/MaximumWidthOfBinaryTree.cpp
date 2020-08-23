#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
typedef pair<TreeNode*, ll> pti;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (NULL == root) return 0;
        queue<pti> q;
        q.push({root, 0LL});
        int res = 1;
        while (!q.empty()) {
            int sz = q.size();
            int start_idx = -1;
            ll mn = 1LL<<48, mx = -1;
            FOR(i, sz) {
                pti tp = q.front();
                q.pop();
                TreeNode* cur = tp.first;
                ll idx = tp.second;
                mx = max(idx, mx);
                mn = min(idx, mn);
                if (cur->left != NULL) {
                    if (start_idx < 0) {
                        start_idx = idx * 2;
                    }
                    q.push({cur->left, idx * 2 - start_idx});
                }
                if (cur ->right != NULL) {
                    if (start_idx < 0) {
                        start_idx = idx * 2 + 1;
                    }
                    q.push({cur->right, idx * 2 + 1 - start_idx});
                }
            }
            res = max(res, (int)(mx - mn + 1));
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}
