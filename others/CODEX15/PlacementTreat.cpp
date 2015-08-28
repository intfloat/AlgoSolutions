#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9 + 7);
inline ll get(const int N, const vector<int>& den) {
    if (N < 0) return 0ll;
    vector<ll> cnt(N + 1, 0);
    cnt[0] = 1;
    FOR(i, den.size()) for (int j = den[i]; j <= N; ++j) {
        cnt[j] = (cnt[j] + cnt[j - den[i]]) % MOD;
    }
    return cnt[N];
}
inline void solve() {
    int N, M, x, y;
    scanf("%d %d", &N, &M);
    vector<int> den(M);
    FOR(i, M) scanf("%d", &den[i]);
    scanf("%d %d", &x, &y);
    --x; --y;
    ll res = 0;
    if (x != y) res = get(N - den[x] - den[y], den);
    else res = get(N - den[x], den);
    vector<int> dd;
    FOR(i, M) {
        if (i != x && i != y) {
            dd.push_back(den[i]);
        }
    }
    res = (res + get(N, dd)) % MOD;
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
