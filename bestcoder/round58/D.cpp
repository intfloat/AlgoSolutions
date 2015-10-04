#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 105;
typedef long long ll;
int degree[N];
ll C[N][N], MOD, com[N][N];
inline void preprocess() {
    memset(com, 0, sizeof com);
    for (int i = 0; i < N; ++i) com[i][0] = 1;
    for (int j = 1; j < N; ++j) {
        for (int i = j; i < N; ++i) {
            com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % MOD;
        }
    }
}
ll det(ll a[N][N], int n) {
    ll ret = 1;
    bool neg = false;
    for (int i = 1; i < n; ++i) for (int j = 1; j < n; ++j) {
        a[i][j] %= MOD;
        a[i][j] = (a[i][j] + MOD) % MOD;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            while (a[j][i]) {
                ll t = a[i][i] / a[j][i];
                for (int k = i; k < n; ++k)
                    a[i][k] = ((a[i][k] - a[j][k] * t) % MOD + MOD) % MOD;
                for (int k = i; k < n; ++k)
                    swap(a[i][k], a[j][k]);
                neg = 1 - neg;
            }
        }
        if (a[i][i] == 0) return 0;
        ret = (ret * a[i][i]) % MOD;
    }
    ret %= MOD;
    if (neg) ret = (MOD - ret) % MOD;
    return ret;
}
ll fast_power(ll num, int p) {
  if (p == 0) return 1ll;
  if (p == 1) return num % MOD;
  ll ret = fast_power(num, p / 2);
  ret = (ret * ret) % MOD;
  if (p & 1) ret = (ret * num) % MOD;
  return ret;
}
inline void solve() {
    int n, m, q, x, y;
    scanf("%d %d %lld %d", &n, &m, &MOD, &q);
    preprocess();
    memset(C, 0, sizeof C);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        --x; --y;
        --C[x][y]; --C[y][x];
        ++C[x][x]; ++C[y][y];
    }
    ll res = det(C, n);
    ll tmp = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (i % 2) {
            tmp -= (com[n - 1][i] * fast_power(n - 1 - i, q)) % MOD;
        }
        else {
            tmp += (com[n - 1][i] * fast_power(n - 1 - i, q)) % MOD;
        }
        tmp = (tmp + MOD) % MOD;
    }
    res = (res * tmp) % MOD;
    printf("%lld\n", res);
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
