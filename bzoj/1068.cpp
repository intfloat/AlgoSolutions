#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string s;
    cin >> s;
    int sz = s.size();
    s = "Z" + s;
    vector<vector<bool> > sym(sz + 1, vector<bool>(sz + 1, false));
    for (int i = 1; i <= sz; ++i) {
        for (int j = i + 1; j <= sz; j += 2) {
            string s1 = s.substr(i, (j - i + 1) / 2);
            string s2 = s.substr(i + (j - i + 1) / 2, (j - i + 1) / 2);
            sym[i][j] = (s1 == s2);
        }
    }
    vector<vector<int> > dp(sz + 1, vector<int>(sz + 1, 1 << 20));
    for (int i = 1; i <= sz; ++i) {
        dp[i][i] = 1;
        for (int j = i + 1; j <= sz; ++j) {
            dp[i][j] = j - i + 1; // not compress at all
            for (int k = i + 1; k <= j; k += 2) {
                if (!sym[i][k]) {
                    continue;
                }
                int cur = (j - k) + dp[i][(i + k) / 2] + 1;
                dp[i][j] = min(dp[i][j], cur);
            }
        }
    }
    vector<int> res(sz + 1);
    res[0] = -1;
    for (int i = 1; i <= sz; ++i) {
        res[i] = i; // not compress at all
        for (int k = i; k >= 1; --k) {
            int cur = dp[k][i] + 1 + res[k - 1];
            res[i] = min(res[i], cur);
        }
    }
    cout << res[sz] << endl;
    return 0;
}
