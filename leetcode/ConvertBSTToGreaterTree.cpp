#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;

/**
 * Definition for a binary tree node.
 */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
private:
    int sum;
    void solve(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        solve(root->right);
        int backup = root->val;
        root->val += sum;
        sum += backup;
        solve(root->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        this->sum = 0;
        solve(root);
        return root;
    }
};

int main() {
    Solution solution;
    return 0;
}