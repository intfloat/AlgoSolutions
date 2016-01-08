#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1000005;
vector<bool> prime(MAX_N, true);
vector<int> p;
class MillerRabin {
    vector<int> prime;
    // calculate (a * b) % c
    ll mulmod(ll a, ll b, ll c) {
        if (a < b) swap (a, b);
        ll res = 0, x = a;
        while (b > 0) {
            if (b & 1) {
                res = res + x;
                if (res >= c) res -= c;
            }
            x = x * 2;
            if (x >= c) x -= c;
            b >>= 1;
         }
         return res % c;
    }
    // calculate (a ^ p) % mod
    ll bigmod(ll a, ll p, ll mod) {
        ll x = a, res = 1;
        while (p) {
            if (p & 1) res = mulmod(res, x, mod);
            x = mulmod(x, x, mod);
            p >>= 1;
        }
        return res;
    }
    bool witness(ll a, ll d, ll s, ll n) {
        ll r = bigmod(a, d, n);
        if (r == 1 || r == n - 1) return false;
        int i;
        for (i = 0; i < s - 1; i++) {
            r = mulmod(r, r, n);
            if (r == 1) return true;
            if (r == n - 1) return false;
        }
        return true;
    }
public:
    MillerRabin() {
        prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    }
    bool test(ll n) {
        if (n <= 1) return false;
        int i;
        ll p = n - 1;
        ll s = 0;
        while (!(p & 1)) {
            p /= 2;
            s++;
        }
        ll d = p;
        p = n - 1;
        for (i = 0; i < (int)prime.size() && prime[i] < n; ++i) {
            if (witness(prime[i], d, s, n)) return false;
        }
        return true;
    }
};
MillerRabin mr;
void preprocess() {
    prime[0] = prime[1] = false;
    for (int i = 2; i < MAX_N; ++i) {
        if (prime[i]) {
            for (int j = i + i; j < MAX_N; j += i) {
                prime[j] = false;
            }
            p.push_back(i);
        }
    }
}
inline void solve() {
    ll x;
    scanf("%lld", &x);
    if (x == 1) {
        printf("1\n");
        return;
    }
    if (mr.test(x)) {
        printf("%lld\n", x);
        return;
    }
    vector<pii> fac;
    int g = 0;
    ll t = 0;
    for (t = 0; p[t] <= x && t < (int)p.size(); ++t) {
        if (x % p[t] == 0) {
            int cnt = 0;
            while (x % p[t] == 0) {
                ++cnt;
                x /= p[t];
            }
            cnt *= 2;
            if (fac.empty()) g = cnt;
            else g = __gcd(g, cnt);
            fac.push_back({p[t], cnt});
        }
    }
    if (x > 1) {
        ll sq = (ll)sqrt(x);
        if (sq * sq != x) {
            printf("-1\n");
            return;
        }
        fac.push_back({sq, 4});
        g = __gcd(g, 4);
    }
    for (int i = g; i >= 1; --i) {
        if (g % i == 0) {
            int cc = 1;
            FOR(j, fac.size()) {
                cc *= (fac[j].second / i + 1);
            }
            if (cc == i) {
                ll res = 1;
                FOR(j, fac.size()) {
                    FOR(k, fac[j].second / i) res *= fac[j].first;
                }
                printf("%lld\n", res);
                return;
            }
        }
    }
    printf("-1\n");
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
