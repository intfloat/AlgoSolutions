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
const ll MOD = 998244353ll;
const int MAX_N = 100005;
vector<ll> cur(MAX_N, 0), pv(MAX_N, 0), dp(MAX_N, 0);
void preprocess() {
    pv[0] = 1; dp[0] = 1;
    for (int i = 1; ; ++i) {
        if (2 * MAX_N < i * (i - 1)) break;
        fill(cur.begin(), cur.end(), 0ll);
        for (int j = i; j < MAX_N; ++j) {
            cur[j] = (cur[j - i] + pv[j - i]) % MOD;
        }
        FOR(j, MAX_N) dp[j] = (dp[j] + cur[j]) % MOD;
        pv = cur;
    }
    return;
}
int main() {
    int T, N, C, L, R;
    preprocess();
    cin >> T;    
    FOR(tt, T) {
        cin >> N >> C >> L >> R;
        L -= C; R -= C;        
        ll res = 0;
        for (int i = L; i <= R; ++i) res = (res + dp[i]) % MOD;
        cout << res % MOD << endl;
    }
    return 0;
}
