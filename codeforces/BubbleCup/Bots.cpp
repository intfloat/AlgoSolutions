#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
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
int main() {
    int N;
    scanf("%d", &N);
    vector<ll> twos(2 * N + 1);
    twos[0] = 1ll;
    for (int i = 1; i < twos.size(); ++i) {
        twos[i] = (twos[i - 1] * 2ll) % MOD;
    }
    vector<ll> dp(2 * N + 1, 0);
    ll val = 1, res = 0;
    for (int i = 0; i <= 2 * N; ++i) {
        if (i - 1 < N) {
            dp[i] = twos[i];
        }
        else {
            if (i - 1 == N) val = 1ll;
            else {
                val = (val * (i - 1)) % MOD;
                val = (val * inv(i - 1- N)) % MOD;
            }
            dp[i] = 2ll * (dp[i - 1] - val) % MOD;
            dp[i] = (dp[i] + MOD) % MOD;
        }
        res = (res + dp[i]) % MOD;
    }
    cout << res << endl;
    return 0;
}
