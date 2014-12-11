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
const int MOD = 1000000007;
const int MAX_N = 10005;
ll euler[MAX_N];

void precompute() {
    FOR(i, MAX_N) euler[i] = i;
    for (int i = 2; i < MAX_N; ++i) {
        // prime number
        if (euler[i] == i) {
            euler[i] = i - 1;
            for (int j = 2 * i; j < MAX_N; j += i) {
                euler[j] = euler[j] * (i - 1) / i;
                euler[j] %= MOD;
            }
        }
    }
    return;
}

ll fastPower(ll number, int p) {
    ll res = 1;
    number %= MOD;
    while (p) {
        if (p & 1) res = (res * number) % MOD;
        number = (number * number) % MOD;
        p >>= 1;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    precompute();
    FOR(cc, T) {
        ll color, n;
        cin >> color >> n;
        ll res = 0;
        for (int i = 1; i <= n; ++i) {
            if (n % i) continue;
            res = (res + euler[i] * fastPower(color, n / i)) % MOD;
        }
        if (n % 2) res = (res + n * fastPower(color, n / 2 + 1)) % MOD;
        else res = (res + (n / 2) * fastPower(color, n / 2 + 1) + (n / 2) * fastPower(color, n / 2)) % MOD;

        res = (res * fastPower(2 * n, MOD - 2)) % MOD;
        cout << "Case #" << cc + 1 << ": " << res % MOD << endl;
    }
    return 0;
}
