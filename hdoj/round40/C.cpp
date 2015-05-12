#include <vector>
#include <algorithm>
#include <iostream>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

int x1, y11, x2, y2, p;
ll fac[100005];
ll pw(ll number, ll cnt) {
    if (cnt == 0) return 1ll;
    if (cnt == 1) return number % p;
    ll t = pw(number, cnt / 2);
    t = (t * t) % p;
    if (cnt % 2) t = (t * number) % p;
    return t;
}

inline ll inv(ll number) {
    return pw(number, p - 2);
}

ll lucas(int n, int m) {
    if (m > n) return 0;
    if (m == n) return 1;
    ll res = 0ll;
    if (n < p && m < p) {
        res = fac[n] * ((inv(fac[m]) * inv(fac[n - m])) % p);
        res %= p;
    }
    else {
        res = lucas(n / p, m / p) % p;
        res *= lucas(n % p, m % p) % p;
        res %= p;
    }
    return res;
}

int main() {
    while (cin >> x1 >> y11 >> x2 >> y2 >> p) {
        ll res = 0ll;
        fac[0] = fac[1] = 1ll;
        for (int i = 2; i < min(x2, p) + 2; ++i) fac[i] = (fac[i - 1] * i) % p;
        for (int i = y11; i <= y2; ++i) {
            res = (res + lucas(x2 + 1, i + 1) - lucas(x1, i + 1)) % p;
            res = (res + p) % p;
        }
        cout << res << endl;
    }
    return 0;
}
