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
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;

ll multiMod(ll a, ll b, ll mod) {
    a %= mod; b %= mod;
    ll res = 0;
    while (b > 0) {
        if (b & 1) {
            res = (res + a) % mod;
        }
        a = (a << 1) % mod;
        b >>= 1;
    }
    return res;
}

ll fastModPow(ll rnd, ll p, ll mod) {
    if (p == 0) return 1ll;
    if (p == 1) return rnd % mod;
    ll tmp = fastModPow(rnd, p / 2, mod) % mod;
    tmp = multiMod(tmp, tmp, mod);
    if (p & 1) tmp = multiMod(tmp, rnd, mod);
    return tmp;
}

bool Witness(ll a,ll n) {
    ll t = 0, u = n - 1;
    while(!(u&1)) {
        t++;
        u /= 2;
    }
    ll x0 = fastModPow(a, u, n);
    for(int i = 1; i <= t; i++) {
        ll x1 = multiMod(x0, x0, n);
        if(x1 == 1 && x0 != 1 && x0 != (n - 1))
            return true;
        x0 = x1;
    }
    if(x0 != 1)
        return true;
    return false;
}

bool isPrime(ll number) {
    if (number == 2) return true;
    FOR(i, 100) {
        ll rnd = rand() % (number - 1) + 1;
        // rnd = (rand() * rnd + rand()) % (number - 1) + 1;
        // rnd = rnd * rnd + rand();
        // rnd = min(rnd, number - 1);
        // cout << i << " " << rnd << " " << fastModPow(rnd, number - 1, number) << endl;
        if (Witness(rnd, number)) return false;
        // if (fastModPow(rnd, number - 1, number) != 1) return false;
    }
    return true;
}

ll Pollard_Rho(ll number, int c) {
    ll x = rand() % number, y = x;
    int k = 2, i = 1;
    while (true) {
        ++i;
        x = (multiMod(x, x, number) + c) % number;
        ll t = max(y - x, x - y);
        ll g = __gcd(t, number);
        // cout << x << " " << y << " " << g << endl;
        if (g != 1 && g != number) return g;
        if (x == y) return number;
        if (i == k) {
            k = 2 * k;
            y = x;
        }
    }
    // should not reach here
    return number;
}

ll getFactor(ll number) {
    if ((number & 1) == 0) return 2ll;
    if (number < 10000) {
        for (int i = 3; i * i <= number; i += 2) {
            if (number % i == 0) return i;
        }
    }
    if (isPrime(number)) return number;
    int c = 112;
    ll f;
    while (true) {
        f = Pollard_Rho(number, c);
        // cout << "f: " << f << " number: " << number << endl;
        if (f == number) --c;
        else break;
    }
    // assert(number % f == 0);
    return min(getFactor(f), getFactor(number / f));
}

int main() {
    int T;
    ll number;
    cin >> T;
    while (T--) {
        cin >> number;
        if (isPrime(number)) { cout << "Prime" << endl; }
        else cout << getFactor(number) << endl;
    }
    return 0;
}
