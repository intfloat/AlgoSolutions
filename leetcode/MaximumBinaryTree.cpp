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
class Solution {
private:
    TreeNode* getTree(const vector<int>& nums, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int idx = max_element(nums.begin() + left, nums.begin() + right + 1) - nums.begin();
        TreeNode* node = new TreeNode(nums[idx]);
        node->left = getTree(nums, left, idx - 1);
        node->right = getTree(nums, idx + 1, right);
        return node;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return getTree(nums, 0, (int)nums.size() - 1);
    }
};
