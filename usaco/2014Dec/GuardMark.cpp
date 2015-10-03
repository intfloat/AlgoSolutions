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
struct Cow {
    int h, w, st;
};
vector<Cow> cows;
vector<ll> wdict, hdict;
vector<ll> dp;
const ll INF = static_cast<ll>(1e14);
ll N, H;

void precompute() {
    FOR(i, 1 << N) {
        ll wei = 0, hei = 0;
        FOR(j, N) {
            if (i & (1<<j)) {
                wei += cows[j].w;
                hei += cows[j].h;
            }
        }
        wdict[i] = wei;
        hdict[i] = hei;
    }
    return;
}

ll solve(int C) {
    if (C == 0) return INF;
    if (dp[C] != INF) return dp[C];
    dp[C] = -INF;
    FOR(i, N) {
        if (C & (1<<i)) {
            int nx = C & (~(1<<i));
            ll tmp = cows[i].st - wdict[nx];
            // without this pruning strategy, it would get TLE...
            if (tmp < 0) continue;
            dp[C] = max(dp[C], min(solve(nx), tmp));
        }
    }
    return dp[C];
}

int main() {
    cin >> N >> H;
    cows.resize(N); dp.resize(1 << N);
    wdict.resize(1 << N); hdict.resize(1 << N);
    FOR(i, dp.size()) dp[i] = INF;
    FOR(i, N) cin >> cows[i].h >> cows[i].w >> cows[i].st;
    precompute();
    ll res = -1;
    FOR(i, 1 << N) {
        if (hdict[i] >= H) {
            ll cur = solve(i);
            res = max(res, cur);
        }
    }
    if (res >= 0) cout << res << endl;
    else cout << "Mark is too tall" << endl;
    return 0;
}
