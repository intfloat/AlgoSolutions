#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) {
            return 0;
        }
        string rs = s;
        reverse(rs.begin(), rs.end());
        int sz = s.size();
        vector<vector<int> > dp(sz, vector<int>(sz, 0));
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                if (rs[i] == s[j]) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                } else {
                    if (i > 0) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                    }
                    if (j > 0) {
                        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                    }
                }
            }
        }
        int res = min(1, sz);
        for (int i = 0; i < sz - 1; ++i) {
            res = max(res, dp[i][sz - i - 2] * 2);
            if (i - 1 >= 0) {
                res = max(res, dp[i - 1][sz - i - 2] * 2 + 1);
            }
        }
        return res;
    }
};
