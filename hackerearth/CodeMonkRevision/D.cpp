#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9 + 7);
map<ll, ll> memo;
inline void factor(vector<ll>& ret, ll& num) {
    ret.clear();
    ret.push_back(1ll);
    ll i = 2;
    for (i = 2; i * i < num; ++i) {
        if (num % i == 0) {
            ret.push_back(i);
            ret.push_back(num / i);
        }
    }
    if (i * i == num) ret.push_back(i);
}
ll fast_power(ll num, ll p) {
  if (p == 0) return 1ll;
  if (p == 1) return num % MOD;
  ll ret = fast_power(num, p / 2);
  ret = (ret * ret) % MOD;
  if (p % 2) ret = (ret * num) % MOD;
  return ret;
}
ll solve(ll num) {
    if (memo.find(num) != memo.end()) {
        return memo[num];
    }
    vector<ll> fs;
    --num;
    factor(fs, num);
    ll res = 0ll;
    FOR(i, fs.size()) {
        res = (res + fast_power(solve(fs[i]), num / fs[i])) % MOD;
    }
    memo[num + 1] = res;
    return res;
}
int main() {
    ll N;
    scanf("%lld", &N);
    memo[1ll] = 1; memo[2ll] = 1;
    printf("%lld\n", solve(N));
    return 0;
}
