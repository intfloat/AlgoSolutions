// from Mohammad Samiul Islam
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int main() {
    MillerRabin mr;
    for (int i = 1; i < 100; ++i) {
        if (mr.test(i)) {
            printf("Prime: %d\n", i);
        }
    }
    return 0;
}
