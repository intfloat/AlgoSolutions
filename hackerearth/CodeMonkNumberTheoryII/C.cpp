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
ll fac[105], com[105][105], seq[105];
inline void preprocess() {
    fac[0] = fac[1] = 1;
    for (int i = 2; i < 105; ++i) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    for (int i = 1; i < 105; ++i) {
        for (int j = 0; j <= i; ++j) {
            ll tmp = (fac[i] * inv(fac[j])) % MOD;
            com[i][j] = (tmp * inv(fac[i - j])) % MOD;
        }
    }
    seq[0] = 1; seq[1] = 0; seq[2] = 1; seq[3] = 2;
    for (int i = 4; i < 105; ++i) {
        seq[i] = ((ll)(i - 1) * (seq[i - 1] + seq[i - 2])) % MOD;
    }
}
int main() {
    preprocess();
    int N, L, R;
    cin >> N >> L >> R;
    ll Q = fac[N];
    ll P = 0;
    for (int i = L; i <= R; ++i) {
        P = (P + com[N][i] * seq[i]) % MOD;
    }
    ll res = (P * inv(Q)) % MOD;
    cout << res << endl;
    return 0;
}
