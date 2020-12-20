
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        res.push_back(1);
        bool to_right = true;
        for (int delta = k; delta >= 1; --delta) {
            if (to_right) {
                res.push_back(res.back() + delta);
            } else {
                res.push_back(res.back() - delta);
            }
            to_right = !to_right;
        }
        for (int i = k + 2; i <= n; ++i) {
            res.push_back(i);
        }
        return res;
    }
};
