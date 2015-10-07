#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = (ll)(1e9 + 7);
ll fast_power(ll num, int p) {
  if (p == 0) return 1ll;
  if (p == 1) return num % MOD;
  ll ret = fast_power(num, p / 2);
  ret = (ret * ret) % MOD;
  if (p & 1) ret = (ret * num) % MOD;
  return ret;
}
int main() {
    int n;
    scanf("%d", &n);
    ll res = 0;
    FOR(i, 3) FOR(j, 3) FOR(k, 3) {
        if (i + j + k + 3 == 6) ++res;
    }
    ll total = fast_power(3 * 3 * 3ll, n);
    res = (total - fast_power(res, n)) % MOD;
    res = (res + MOD) % MOD;
    cout << res << endl;
    return 0;
}
