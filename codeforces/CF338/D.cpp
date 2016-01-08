#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll MOD = (ll)(1e9 + 7);
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
int main() {
    int m, num;
    scanf("%d", &m);
    map<int, int> cnt;
    FOR(i, m) {
        scanf("%d", &num);
        ++cnt[num];
    }
    ll tot = 1;
    --MOD;
    bool flag = false;
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        int tmp = (it->second + 1);
        if (!flag && tmp % 2 == 0) {
            flag = true;
            tmp /= 2;
            tot = (tot * tmp) % MOD;
        }
        else {
            tot = (tot * tmp) % MOD;
        }
    }
    map<int, ll> mp;
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        ll tmp = 0;
        if (!flag) {
            tmp = it->second / 2;
        }
        else tmp = it->second;
        mp[it->first] = (tot * tmp) % MOD;
    }
    ++MOD;
    ll res = 1;
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        ll tmp = fast_power(it->first, mp[it->first]) % MOD;
        res = (res * tmp) % MOD;
    }
    cout << res << endl;
    return 0;
}
