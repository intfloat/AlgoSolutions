class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int sz1 = s1.size(), sz2 = s2.size();
        vector<vector<int> > dp(sz1 + 1, vector<int>(sz2 + 1, 0));

        for (int i = 1; i <= sz1; ++i) {
            for (int j = 1; j <= sz2; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < sz1; ++i) res += s1[i];
        for (int i = 0; i < sz2; ++i) res += s2[i];
        res -= 2 * dp[sz1][sz2];
        return res;
    }
};
