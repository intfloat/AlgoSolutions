#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>
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
vector<ll> twos(100005);
inline void preprocess() {
    twos[0] = 1;
    for (int i = 1; i < (int)twos.size(); ++i) {
        twos[i] = (2ll * twos[i - 1]) % MOD;
    }
}
inline void solve() {
    int n;
    scanf("%d", &n);
    vector<ll> arr(n);
    FOR(i, n) scanf("%lld", &arr[i]);
    map<ll, ll> mp, pos;
    ll res = 0;
    FOR(i, n) {
        if (pos.find(arr[i]) == pos.end()) {
            res = (res + arr[i] * twos[n - 1]) % MOD;
            mp[arr[i]] = twos[n - 1];
        }
        else {
            ll val = (mp[arr[i]] * inv(twos[i - pos[arr[i]]])) % MOD;
            ll tmp = (twos[n - 1] - val) % MOD;
            tmp = (tmp + MOD) % MOD;
            res = (res + arr[i] * tmp) % MOD;
            mp[arr[i]] = (val + twos[n - 1]) % MOD;
        }
        pos[arr[i]] = i;
    }
    printf("%lld\n", res);
}
int main() {
    preprocess();
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
