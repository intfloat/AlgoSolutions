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
    int n;
    while (cin >> n && n != -1) {
        if (n == 0) { cout << 0 << endl; continue; }
        ll res = 0;
        for (int i = 1; i <= n; ++i) res += fastPower(3, __gcd(i, n));
        if (n % 2 == 0) res += (n / 2) * fastPower(3, n / 2 + 1) + (n / 2) * fastPower(3, n / 2);
        else res += n * fastPower(3, n / 2 + 1);
        cout << res / (2 * n) << endl;
    }
    return 0;
}
