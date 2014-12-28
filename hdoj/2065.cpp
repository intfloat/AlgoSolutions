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

typedef unsigned long long ll;
const int MOD = 100;

ll fast_power(ll number, ll p) {
    ll res = 1;
    while (p > 0) {
        if (p & 1) res = (res * number) % MOD;
        p >>= 1;
        number = (number * number) % MOD;
    }
    return res;
}

int main() {
    int T;
    while (cin >> T && T != 0) {
        ll N;
        FOR(i, T) {
            cin >> N;
            ll res = fast_power(4ll, N - 1) + fast_power(2ll, N - 1);
            cout << "Case " << i + 1 << ": "<< res % MOD << endl;            
        }
        cout << endl;
    }
    return 0;
}
