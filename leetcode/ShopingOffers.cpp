class Solution {
private:
    vector<int> price;
    vector<vector<int>> special;
    map<int, int> dp;

    int solve(vector<int>& cur_needs) {
        int key = to_key(cur_needs);
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }
        int val = 0;
        for (int i = 0; i < price.size(); ++i) {
            val += cur_needs[i] * price[i];
        }
        for (auto& s : special) {
            if (ok(cur_needs, s)) {
                for (int i = 0; i < cur_needs.size(); ++i) {
                    cur_needs[i] -= s[i];
                }
                int cost = solve(cur_needs) + s.back();
                val = min(cost, val);
                for (int i = 0; i < cur_needs.size(); ++i) {
                    cur_needs[i] += s[i];
                }
            }
        }
        dp[key] = val;
        return val;
    }

    int to_key(vector<int>& v) {
        int ret = 0;
        for (int i = 0; i < v.size(); ++i) {
            ret = ret * 10 + v[i];
        }
        return ret;
    }
    bool ok(vector<int>& needs, vector<int>& s) {
        for (int i = 0; i < needs.size(); ++i) {
            if (s[i] > needs[i]) {
                return false;
            }
        }
        return true;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        this->price = price;
        this->special = special;
        dp.clear();
        dp[0] = 0;
        return solve(needs);
    }
};
