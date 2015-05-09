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

const ll MOD = static_cast<ll>(1e9 + 7);
vector<ll> perm(105, 0), fac(105, 1);
void preprocess() {
    perm[1] = 0; fac[1] = 1;
    perm[2] = 1;
    for (int i = 2; i < fac.size(); ++i) fac[i] = (fac[i - 1] * i) % MOD;
    for (int i = 3; i < perm.size(); ++i) {
        for (int j = i; j >= 1; --j)
            perm[i] = (perm[i] + (j - 1) * fac[i - 1] + perm[i - 1]) % MOD;
    }
    return;
}
int main() {
    preprocess();
    int n;
    vector<ll> arr;
    while (cin >> n) {
        ll res = 0;
        arr.resize(n);
        FOR(i, n) cin >> arr[i];
        ll cur = 0;
        FOR(i, n) for (int j = i + 1; j < n; ++j) cur += (arr[j] < arr[i]);
        vector<ll> dp(n + 1, 1);
        dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            ll small = 0;
            for (int j = i + 1; j < n; ++j) small += (arr[j] < arr[i]);
            dp[i] = (small * fac[n - 1 - i]) % MOD;
            dp[i] = (dp[i] + dp[i + 1]) % MOD;
        }
        FOR(i, n) {
            ll small = 0;
            for (int j = i + 1; j < arr.size(); ++j) {
                if (arr[j] < arr[i]) ++small;
            }
            for (int j = 1; j <= small; ++j) {
                res = (res + perm[n - 1 - i] + (j - 1) * fac[n - 1 - i]) % MOD;
            }
            res = (res + small * dp[i + 1]) % MOD;
        }        
        cout << (res - cur + MOD) % MOD << endl;
    }
    return 0;
}
