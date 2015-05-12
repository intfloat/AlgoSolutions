#include <iostream>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const int MAX_N = 100005;
int p, T;
ll fac[MAX_N];

ll pw(ll num, int pp) {
    if (pp == 0) return 1ll;
    if (pp == 1) return num % p;
    ll t = pw(num, pp / 2);
    t = (t * t) % p;
    if (pp % 2) t = (t * num) % p;
    return t;
}

inline ll inv(ll number) {
    return pw(number, p - 2);
}

ll lucas(int n, int m) {
    if (m > n) return 0;
    if (m == n) return 1;
    ll res = 0;
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
    int n, m;    
    cin >> T;
    FOR(tt, T) {
        cin >> n >> m >> p;
        fac[0] = fac[1] = 1;
        for (int i = 2; i < min(p, m + n) + 1; ++i) fac[i] = (fac[i - 1] * i) % p;
        cout << lucas(n + m, m) << endl;
    }
    return 0;
}
