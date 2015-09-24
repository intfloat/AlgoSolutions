#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9 + 7);
ll fast_power(ll num, int p) {
  if (p == 0) return 1ll;
  if (p == 1) return num % MOD;
  ll ret = fast_power(num, p / 2);
  ret = (ret * ret) % MOD;
  if (p & 1) ret = (ret * num) % MOD;
  return ret;
}
inline ll inv(ll num) {
  return fast_power(num, MOD - 2);
}
ll fac[1005], com[1005][1005];
inline void preprocess() {
    fac[0] = fac[1] = 1;
    for (int i = 2; i < 1005; ++i) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    com[1][0] = com[1][1] = 1;
    for (int i = 2; i < 1005; ++i) {
        com[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % MOD;
        }
    }
}
int main() {
    preprocess();
    int N, K;
    cin >> N >> K;
    ll res = com[N][K];
    vector<ll> dp(N + 1, 0ll);
    dp[0] = dp[1] = 1ll;
    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= i - 1; ++j) {
            ll tmp = (com[i - 1][j] * fac[j + 1]) % MOD;
            dp[i] = (dp[i] + tmp * dp[i - 1 - j]) % MOD;
        }
    }
    res = (res * dp[N]) % MOD;
    cout << res << endl;
    return 0;
}
