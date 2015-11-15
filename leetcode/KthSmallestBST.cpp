// struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
private:
    vector<int> arr;
    int n;
    void solve(TreeNode* root) {
        if (root == NULL || arr.size() >= n) {
            return;
        }
        solve(root->left);
        if (arr.size() < n) {
            arr.push_back(root->val);
        }
        if (arr.size() < n) {
            solve(root->right);
        }
        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        this->n = k;
        solve(root);
        return arr[k - 1];
    }
};
