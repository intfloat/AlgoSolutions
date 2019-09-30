class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz1 = word1.size(), sz2 = word2.size();
        vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, 0));
        for (int i = 1; i <= sz1; ++i) {
            for (int j = 1; j <= sz2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return sz1 + sz2 - 2 * dp[sz1][sz2];
    }
};