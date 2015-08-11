#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 4001;
const ll MOD = (ll)(1e9 + 7);
vector<vector<ll> > f(MAX_N, vector<ll>(MAX_N));
vector<ll> dp(MAX_N, 0);
vector<ll> fac(MAX_N);
inline void preprocess() {
    for (int i = 1; i < MAX_N; ++i) {
        f[i][1] = f[i][i] = 1;
        for (int j = 2; j < i; ++j) {
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j] * j) % MOD;
        }
    }
    dp[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = (dp[i] + f[i][j]) % MOD;
        }
    }
    fac[0] = fac[1] = 1ll;
    for (int i = 2; i < MAX_N; ++i) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    return;
}
ll pw(ll num, ll p) {
    if (p == 0) return 1ll;
    if (p == 1) return num % MOD;
    ll ret = pw(num, p / 2);
    ret = (ret * ret) % MOD;
    if (p % 2) ret = (ret * num) % MOD;
    return ret;
}
inline ll get(int n, int cc) {
    ll ret = (fac[n] * pw(fac[cc], MOD - 2)) % MOD;
    ret = (ret * pw(fac[n - cc], MOD - 2)) % MOD;
    return ret;
}
int main() {
    int n;
    cin >> n;
    preprocess();
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        res = (res + get(n, i) * dp[n - i]) % MOD;
    }
    cout << res << endl;
    return 0;
}
