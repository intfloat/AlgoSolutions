
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    map<int, int> mp;
    int getSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int sm = root->val + getSum(root->left) + getSum(root->right);
        if (mp.find(sm) == mp.end()) {
            mp[sm] = 1;
        } else {
            mp[sm] += 1;
        }
        return sm;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        this->mp.clear();
        this->getSum(root);
        vector<pair<int, int> > freq;
        if (mp.empty()) {
            return vector<int>();
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            freq.push_back({it->second, it->first});
        }
        sort(freq.begin(), freq.end(), greater<pair<int, int> >());
        vector<int> res;
        for (int i = 0; i < (int)freq.size(); ++i) {
            if (freq[i].first == freq[0].first) {
                res.push_back(freq[i].second);
            } else {
                break;
            }
        }
        return res;
    }
};

