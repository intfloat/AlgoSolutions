#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
int main() {
    int n;
    cin >> n;
    vector<ll> color(n), sm(n);
    FOR(i, n) cin >> color[i];
    sm[0] = color[0];
    for (int i = 1; i < n; ++i) sm[i] = sm[i - 1] + color[i];
    int total = sm.back();
    vector<vector<ll> > c(total + 1, vector<ll>(total + 1));
    FOR(i, total + 1) FOR(j, total + 1) {
        if (j == 0) c[i][j] = 1;
        else if (i < j) c[i][j] = 0;
        else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
    vector<ll> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i] = 0;
        for (int j = 0; j <= color[i] - 1; ++j) {
            dp[i] = (dp[i] + dp[i - 1] * c[j + sm[i - 1] - 1][j]) % MOD;
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}
