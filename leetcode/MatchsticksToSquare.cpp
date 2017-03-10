#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> dp;
    vector<int> len;
    int edge_len, sz;
    bool solve(int status) {
        if (dp[status] > 0) {
            return true;
        } else if (dp[status] < 0) {
            return false;
        }
        int sum = 0;
        for (int i = 0; i < sz; ++i) {
            if ((1 << i) & status) {
                continue;
            }
            sum += len[i];
        }
        int rem = sum % edge_len;
        if (rem == 0) {
            rem = edge_len;
        }
        for (int i = 0; i < sz; ++i) {
            if ((1 << i) & status) {
                continue;
            }
            if (len[i] > rem) {
                continue;
            }
            if (solve(status | (1 << i))) {
                dp[status] = 1;
                return true;
            }
        }
        dp[status] = -1;
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 4 || nums.size() < 4) {
            return false;
        }
        len = nums;
        edge_len = total / 4;
        sz = nums.size();
        dp.resize(1 << sz);
        fill(dp.begin(), dp.end(), 0);
        dp[(1 << sz) - 1] = 1;
        return solve(0);
    }
};

int main() {
    Solution sol;
    // std::vector<int> v = {5,5,5,5,16,4,4,4,4,4,3,3,3,3,4};
    std::vector<int> v = {1,1,2,2,2};
    cout << sol.makesquare(v) << endl;
    std::vector<int> u = {3, 3, 3, 3, 4};
    cout << sol.makesquare(u) << endl;
    return 0;
}
