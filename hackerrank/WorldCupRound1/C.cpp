#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 500100;
const int MAX_M = MAX_N * 2;
int head[MAX_N], pnt[MAX_M], nt[MAX_M];
int n, ptr;
ll total;
vector<ll> tokens, dp, mx;
inline void addedge(int from, int to) {
    pnt[ptr] = to; nt[ptr] = head[from]; head[from] = ptr++;
    pnt[ptr] = from; nt[ptr] = head[to]; head[to] = ptr++;
}
inline void init() {
    ptr = 0;
    memset(head, -1, sizeof head);
}
void dfs(int cur, int p) {
    mx[cur] = 0;
    dp[cur] = tokens[cur];
    for (int i = head[cur]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to == p) continue;
        dfs(to, cur);
        dp[cur] += dp[to];
        mx[cur] = max(mx[cur], dp[to]);
    }
    mx[cur] = max(mx[cur], total - dp[cur]);
}
int main() {
    int x, y;
    init();
    scanf("%d", &n);
    tokens.resize(n);
    dp.resize(n); mx.resize(n);
    fill(dp.begin(), dp.end(), 0ll);
    FOR(i, n) scanf("%lld", &tokens[i]);
    total = accumulate(tokens.begin(), tokens.end(), 0ll);
    FOR(i, n - 1) {
        scanf("%d %d", &x, &y);
        --x; --y;
        addedge(x, y);
    }
    dfs(0, -1);
    ll res = total - *min_element(mx.begin(), mx.end());
    printf("%lld\n", res);
    return 0;
}
