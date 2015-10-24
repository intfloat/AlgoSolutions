#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = (ll)(1e9 + 7);
ll fast_power(ll num, ll p) {
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
inline void solve() {
    ll d, k, h;
    scanf("%lld %lld %lld", &d, &k, &h);
    ll res = 0, ds = (d * d) % MOD;
    if (k % 2 == 0) {
        res = (fast_power(ds, k / 2) - 1 + MOD) % MOD;
        res = (res * (d + 1)) % MOD;
        res = (res * d) % MOD;
        ll tmp = (ds - 1 + MOD) % MOD;
        res = (res * inv(tmp)) % MOD;
        res = (res + 1) % MOD;
    }
    else {
        res = (fast_power(ds, (k + 1) / 2) - 1) % MOD;
        ll tmp = (ds - 1 + MOD) % MOD;
        res = (res * inv(tmp)) % MOD;
        res = (res * (d + 1)) % MOD;
    }
    if (k > h) {
        ll rem = 0;
        if ((k - h) % 2) {
            rem = (fast_power(ds, (k - h - 1) / 2 + 1) - 1) % MOD;
            ll tmp = (ds - 1 + MOD) % MOD;
            rem = (rem * inv(tmp)) % MOD;
        }
        else {
            rem = (fast_power(ds, (k - h) / 2) - 1) % MOD;
            ll tmp = (ds - 1 + MOD) % MOD;
            rem = (rem * inv(tmp)) % MOD;
            rem = (rem * d) % MOD;
        }
        res = (res - rem) % MOD;
        res = (res + MOD) % MOD;
    }
    printf("%lld\n", res);
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
