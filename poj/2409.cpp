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

ll fastPower(ll n, int p) {
    if (p == 0) return 1ll;
    if (p == 1) return n;
    ll t = fastPower(n, p / 2);
    t = t * t;
    if (p & 1) t *= n;
    return t;
}

int main() {
    int color, len;
    while (cin >> color >> len) {
        if (!color && !len) break;
        ll res = 0;
        // rotation
        for (int i = 1; i <= len; ++i) {
            res += fastPower(color, __gcd(len, i));
        }
        // reflection
        if (len % 2) res += len * fastPower(color, len / 2 + 1);
        else res += (len / 2) * fastPower(color, len / 2 + 1) + (len / 2) * fastPower(color, len / 2);
        // cout << res << " " << len << endl;
        // assert(res % (2 * len) == 0);
        cout << res / (2 * len) << endl;
    }
    return 0;
}
