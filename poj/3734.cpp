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

const int MOD = 10007;
typedef long long ll;

ll fast_power(ll number, int p) {
    if (p == 0) return 1ll;
    if (p == 1) return number % MOD;
    ll res = 1;
    while (p > 0) {
        if (p & 1) res = (res * number) % MOD;
        number = (number * number) % MOD;
        p >>= 1;
    }
    return res % MOD;
}

int main() {
    int T;
    ll N;
    cin >> T;
    while (T--) {
        cin >> N;
        ll res = fast_power(4ll, N - 1) + fast_power(2, N - 1);
        cout << res % MOD << endl;
    }
    return 0;
}
