#include <bits/stdc++.h>
using namespace std;

int dp[2][105][105];
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    dp[i][j][k] = 0;
                }
            }
        }
        int sz = strs.size();
        vector<int> zeros(sz, 0), ones(sz, 0);
        for (int i = 0; i < strs.size(); ++i) {
            string& s = strs[i];
            for (int j = 0; j < s.size(); ++j) {
                if (s[j] == '0') ++zeros[i];
                else ++ones[i];
            }
        }
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    int cur = i % 2;
                    int prev = 1 - cur;
                    int r1 = dp[prev][j][k];
                    int r2 = 0;
                    if (j >= zeros[i] && k >= ones[i]) {
                        r2 = dp[prev][j - zeros[i]][k - ones[i]] + 1;
                    }
                    dp[cur][j][k] = max(r1, r2);
                }
            }
        }
        return dp[(sz - 1) % 2][m][n];
    }
};

int main() {
    return 0;
}
