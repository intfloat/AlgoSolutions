#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
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
int N;
vector<int> arr;
const int MAX_N = 100005;
vector<pii> fac[MAX_N];
vector<bool> prime(MAX_N, true);
void preprocess() {
    prime[0] = prime[1] = false;
    for (int i = 2; i < MAX_N; ++i) {
        if (prime[i]) {
            fac[i].push_back(make_pair(i, 1));
            for (int j = i + i; j < MAX_N; j += i) {
                int cnt = 0, tmp = j;
                while (tmp % i == 0) {
                    tmp /= i;
                    ++cnt;
                }
                fac[j].push_back(make_pair(i, cnt));
                prime[j] = false;
            }
        }
    }
}
ll A[MAX_N];
inline void solve() {
    FOR(i, N + 1) A[i] = 0;
    for (int i = 2; i <= N; ++i) {
        FOR(j, fac[i].size()) {
            int p = fac[i][j].first, c = fac[i][j].second;
            A[p] = (A[p] + (ll)c * arr[i]) % (MOD - 1);
        }
    }
    vector<ll> pre(N + 2), suf(N + 2);
    pre[1] = (A[1] + 1) % (MOD - 1);
    for (int i = 2; i <= N; ++i) {
        pre[i] = ((A[i] + 1) % (MOD - 1) * pre[i - 1]) % (MOD - 1);
    }
    suf[N + 1] = 1;
    suf[N] = (A[N] + 1) % (MOD - 1);
    for (int i = N - 1; i >= 1; --i) {
        suf[i] = ((A[i] + 1) % (MOD - 1) * suf[i + 1]) % (MOD - 1);
    }
    ll res = 1ll;
    for (int i = 2; i <= N; ++i) {
        if (prime[i]) {
            ll tmp = A[i];
            if (tmp % 2 == 0) {
                tmp = (tmp / 2ll) % (MOD - 1);
                tmp = tmp * ((A[i] + 1) % (MOD - 1));
                tmp %= MOD - 1;
            }
            else {
                tmp = (A[i] + 1) / 2ll;
                tmp %= (MOD - 1);
                tmp = ((A[i] % (MOD - 1)) * tmp) % (MOD - 1);
            }
            tmp = (tmp * pre[i - 1]) % (MOD - 1);
            tmp = (tmp * suf[i + 1]) % (MOD - 1);
            res = (res * fast_power((ll)i, tmp)) % MOD;
        }
    }
    printf("%lld\n", res);
}
int main() {
    preprocess();
    while (scanf("%d", &N) != EOF) {
        arr.resize(N + 1);
        FOR(i, N) scanf("%d", &arr[i + 1]);
        solve();
    }
    return 0;
}
