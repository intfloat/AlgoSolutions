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
    return 0;
}
