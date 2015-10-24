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

const int MAX_N = 1000005;
vector<int> fac[MAX_N];
vector<bool> prime(MAX_N, true);
void preprocess() {
    prime[0] = prime[1] = false;
    for (int i = 2; i < MAX_N; ++i) {
        if (prime[i]) {
            fac[i].push_back(i);
            for (int j = i + i; j < MAX_N; j += i) {
                fac[j].push_back(i);
                prime[j] = false;
            }
        }
    }
}
int main() {
    int n, q, x;
    preprocess();
    scanf("%d %d", &n, &q);
    vector<int> cnt(MAX_N, 0);
    ll num = 1, den = 1;
    FOR(i, MAX_N) {
        if (prime[i]) {
            den = (den * (i - 1)) % MOD;
            num = (num * (i - 1)) % MOD;
        }
    }
    den = inv(den);
    FOR(i, q + 1) {
        if (i == 0) x = n;
        else scanf("%d", &x);
        FOR(j, fac[x].size()) {
            int cur = 0, tmp = x, f = fac[x][j];
            while (tmp % f == 0) {
                ++cur;
                tmp /= f;
            }
            ll old = (fast_power(f, cnt[f] + 1) - 1 + MOD) % MOD;
            num = (num * inv(old)) % MOD;
            cnt[f] += cur;
            ll nn = (fast_power(f, cnt[f] + 1) - 1 + MOD) % MOD;
            num = (num * nn) % MOD;
        }
        ll res = (num * den) % MOD;
        if (i > 0) printf("%lld\n", res);
    }
    return 0;
}
