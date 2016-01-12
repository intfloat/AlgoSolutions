#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = (ll)(1e9 + 7);
ll brute(ll k, ll n) {
    ll res = 0;
    for (ll i = 1; i <= n; ++i) {
        res = (res + k % i) % MOD;
    }
    return res;
}
int main() {
    ll n, k;
    ll res = 0;
    cin >> k >> n;
    // cout << "brute force: " << brute(k, n) << endl;
    if (n > k) {
        res = ((n - k) % MOD) * (k % MOD);
        res %= MOD;
        n = k;
    }
    ll cur = 1;
    for (; cur * cur <= k && cur <= n; ++cur) {
        res += k % cur;
        res %= MOD;
    }
    for (ll i = 1; i * i <= k; ++i) {
        ll up = min(n, k / i);
        ll low = max(cur, k / (i + 1) + 1);
        if (low > up) continue;
        ll val = 0;
        if ((up + low) % 2 == 0) {
            val = (up + low) / 2;
            val %= MOD;
            val = (val * ((up - low + 1) % MOD)) % MOD;
        }
        else {
            val = (up - low + 1) / 2;
            val %= MOD;
            val = (val * ((up + low) % MOD)) % MOD;
        }
        ll tmp = i * (val % MOD);
        tmp %= MOD;
        ll t2 = (k % MOD) * ((up - low + 1) % MOD);
        t2 %= MOD;
        res += ((t2 - tmp) % MOD + MOD) % MOD;
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}
