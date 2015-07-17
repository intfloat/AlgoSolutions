#include <bits/stdc++.h>
using namespace std;
inline void solve() {
    string s;
    int n, k;
    cin >> n >> k;
    cin >> s;
    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1] + 1;
        int ptr = i - 1;
        while (ptr >= 0 && s[ptr] != s[ptr + 1]) {
            --ptr;
        }
        if (i + 1 <= k && ptr >= 0) {
            dp[i] = 0;
            continue;
        }
        for (int j = ptr - 1; j >= 0; --j) {
            if (i - j > k) {
                break;
            }
            dp[i] = min(dp[i], dp[j] + 1);
        }

    }
    cout << dp[n - 1] << endl;
    return;
}
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
