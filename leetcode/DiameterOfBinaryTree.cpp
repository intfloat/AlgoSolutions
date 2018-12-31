#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;

/**
 * Definition for a binary tree node.
 **/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
private:
    int diameter;
    int solve(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);
        this->diameter = max(this->diameter, l + r);
        return max(l, r) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        this->diameter = 0;
        solve(root);
        return this->diameter;
    }
};

int main() {
    Solution solution;
    return 0;
}