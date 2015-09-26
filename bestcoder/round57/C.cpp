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
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
int cnt[11][11][101];
const ll MOD = 1000000007;
map<string, int> mp;
void dfs(string cur, int pos, int mx) {
    if (pos >= 10) return;
    map<string, int>::iterator it;
    for (int i = 0; i <= mx + 1; ++i) {
        string ns = cur + (char)('0' + i);
        FOR(j, ns.size()) ++mp[ns.substr(j, ns.size() - j)];
        ++cnt[pos + 1][max(mx, i)][mp.size()];
        dfs(ns, pos + 1, max(mx, i));
        FOR(j, ns.size()) {
            it = mp.find(ns.substr(j, ns.size() - j));
            if (it->second == 1) mp.erase(it);
            else --mp[ns.substr(j, ns.size() - j)];
        }
    }
}
inline void solve() {
    int n, m, K;
    scanf("%d %d %d", &n, &m, &K);
    ll res = 0;
    vector<ll> perm;
    perm.push_back(1);
    for (int i = 1; i <= min(n, K); ++i) {
        ll val = (perm.back() * (K + 1 - i)) % MOD;
        perm.push_back(val);
    }
    for (int i = 0; i < min(n, K); ++i) {
        res = (res + cnt[n][i][m] * perm[i + 1]) % MOD;
    }
    printf("%lld\n", res);
    return;
}
int main() {
    memset(cnt, 0, sizeof cnt);
    dfs("", 0, -1);
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
