#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = (ll)(1e9 + 7);
ll K;
ll fast_power(ll num, int p) {
  if (p == 0) return 1ll;
  if (p == 1) return num % K;
  ll ret = fast_power(num, p / 2);
  ret = (ret * ret) % K;
  if (p & 1) ret = (ret * num) % K;
  return ret;
}
ll get_rem(ll num, int p) {
    return fast_power(num, p) % K;
}
void solve() {
    ll A, B, N;
    cin >> A >> B >> N >> K;
    ll res = 0;
    map<ll, ll> acnt, bcnt;
    vector<int> as(K + 1), bs(K + 1);
    for (ll i = 1; i <= K; ++i) {
        as[i] = get_rem(i, A);
        bs[i] = get_rem(i, B);
        ++acnt[as[i]]; ++bcnt[bs[i]];
    }
    ll seg = N / K;
    map<ll, ll> at, bt;
    for (ll i = 1; i <= N % K; ++i) {
        ++at[as[i]]; ++bt[bs[i]];
    }
    for (int i = 0; i < K; ++i) {
        ll aa = (seg % MOD) * acnt[i] + at[i];
        ll bb = (seg % MOD) * bcnt[(K - i) % K] + bt[(K - i) % K];
        aa %= MOD; bb %= MOD;
        ll cur = (aa * bb) % MOD;
        res = (res + cur) % MOD;
    }
    for (ll i = 1; i <= K; ++i) {
        ll rr = (as[i] + bs[i]) % K;
        if (rr == 0) {
            ll cur = seg + ((N % K) >= i);
            res = (res - cur) % MOD;
            res = (res + MOD) % MOD;
        }
    }
    cout << res << endl;
    return;
}
int main() {
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ": ";
        solve();
    }
    return 0;
}
