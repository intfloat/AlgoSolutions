#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 1000003;
ll fast_power(ll num, ll p) {
  p %= MOD - 1;
  ll ret = 1, val = num;
  while (p > 0) {
    if (p & 1) ret = (ret * val) % MOD;
    val = (val * val) % MOD;
    p >>= 1;
  }
  return ret;
}
inline ll inv(ll num) {
  return fast_power(num, MOD - 2);
}
int main() {
    ll n, k;
    cin >> n >> k;
    ll val = 1;
    for (ll i = 0; i < n; ++i) {
        val <<= 1;
        if (val > k) {
            break;
        }
    }
    if (val < k) {
        printf("1 1\n");
        return 0;
    }
    ll num = 0, den = 0;
    ll cnt = 0;
    val = 2;
    while (val <= k - 1) {
        cnt += (k - 1) / val;
        val <<= 1;
    }
    if (k - 1 >= MOD) {
        num = 0;
    } else {
        ll twos = fast_power(2ll, n);
        num = inv(fast_power(2ll, cnt));
        for (int i = 1; i <= k - 1; ++i) {
            ll cur = (twos - i) % MOD;
            num = (num * cur) % MOD;
            num = (num + MOD) % MOD;
        }
    }
    ll FMOD = MOD - 1;
    ll pw = n % FMOD;
    pw *= (k - 1) % FMOD;
    pw %= FMOD;
    pw = (pw - cnt % FMOD) % FMOD;
    pw = (pw + FMOD) % FMOD;
    den = fast_power(2ll, pw);
    num = (den - num) % MOD;
    num = (num + MOD) % MOD;
    cout << num << " " << den << endl;
    return 0;
}
