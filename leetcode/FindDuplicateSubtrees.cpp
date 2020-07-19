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
typedef long long ll;
const ll MOD = (ll)1e9 + 7;
class Solution {
private:
    set<ll> seen_hash, duplicate_hash;
    vector<TreeNode*> duplicate_nodes;
    // 一通质数堆叠的哈希操作稳如狗
    ll merge_hash(int val, ll left_hash, ll right_hash) {
        ll res = (((left_hash + 37) ^ MOD) * (val + 79) + 59) % MOD;
        res = (res * 7) % MOD;
        return (((right_hash + 29) ^ MOD) * res + 97) % MOD;
    }
    ll solve(TreeNode* root) {
        if (root == NULL) {
            return (ll)17;
        }
        ll left_hash = solve(root->left);
        ll right_hash = solve(root->right);
        ll root_hash = merge_hash(root->val, left_hash, right_hash);
        if (seen_hash.find(root_hash) != seen_hash.end()
            && duplicate_hash.find(root_hash) == duplicate_hash.end()) {
            duplicate_hash.insert(root_hash);
            duplicate_nodes.push_back(root);
        }
        seen_hash.insert(root_hash);
        return root_hash;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        this->seen_hash.clear();
        this->duplicate_hash.clear();
        this->duplicate_nodes.clear();
        solve(root);
        return this-> duplicate_nodes;
    }
};
