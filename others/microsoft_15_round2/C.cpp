#include <stdio.h>
#include <limits.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
const int MAX_N = 100005;
typedef long long ll;
int colors[MAX_N], N, K;
ll dp[1 << 16], cost[16][1 << 16], cnt[16][16], pv[16];
map<int, int> pos;
void solve() {
    pos.clear();
    FOR(i, 16) pos[1 << i] = i;    
    scanf("%d %d", &N, &K);
    FOR(i, N) scanf("%d", colors + i);
    FOR(i, N) --colors[i];
    memset(cnt, 0, sizeof cnt);    
    memset(pv, 0, sizeof pv);
    FOR(i, N) {
        FOR(j, K) {
            if (colors[i] != j) cnt[colors[i]][j] += pv[j];
        }
        ++pv[colors[i]];
    }
    int total = (1 << K);
    FOR(i, K) cost[i][0] = 0;
    for (int i = 0; i < K; ++i) {
        for (int j = 1; j < total; ++j) {
            if (j & (1 << i)) continue;
            int t = j & (-j);
            int color = pos[t];
            cost[i][j] = cost[i][j - t] + cnt[color][i];
        }
    }
    FOR(i, total) dp[i] = LLONG_MAX;
    dp[0] = 0;
    for (int i = 0; i < total; ++i) {
        if (dp[i] == LLONG_MAX) continue;
        for (int j = 0; j < K; ++j) {
            if (i & (1 << j)) continue;
            dp[i + (1 << j)] = min(dp[i + (1 << j)], dp[i] + cost[j][i]);
        }
    }
    printf("%lld\n", dp[total - 1]);
}

int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        printf("Case #%d: ", tt + 1);
        solve();
    }
    return 0;
}
