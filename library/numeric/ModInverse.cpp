#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// a * x + b * y = gcd(a, b), return gcd(a, b)
// answers will be stored in variables x and y
ll extGcd(ll a, ll b, ll& x, ll& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    int g = extGcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
  }
}
// ASSUME: gcd(a, m) == 1, m is greater than a
// return minimal positive a^(-1) (mod m)
ll modInv(ll a, ll m) {
  ll x, y;
  extGcd(a, m, x, y);
  return (x % m + m) % m;
}
const ll MOD = (ll)(1e9 + 7);
ll fast_power(ll num, int p) {
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
    return 0;
}
