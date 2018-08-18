#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int k_size = key.size();
        int r_size = ring.size();
        vector<vector<int> > dp(k_size, vector<int>(r_size, INT_MAX / 2));
        for (int i = 0; i < k_size; ++i) {
            for (int j = 0; j < r_size; ++j) {
                if (key[i] != ring[j]) {
                    continue;
                } else if (i == 0) {
                    dp[i][j] = min(j, r_size - j);
                } else {
                    for (int k = 0; k < r_size; ++k) {
                        int distance = 0;
                        if (k <= j) {
                            distance = min(j - k, k + r_size - j);
                        } else {
                            distance = min(k - j, j + r_size - k);
                        }
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + distance);
                    }
                }
            }
        }
        return k_size + *min_element(dp[k_size - 1].begin(), dp[k_size - 1].end());
    }
};

int main() {
    Solution sol;
    string ring = "godding";
    string key = "gd";
    // it should be 4
    cout << sol.findRotateSteps(ring, key) << endl;
    return 0;
}