#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge {
    int u, v, l, r;
    Edge(int _u, int _v, int _l, int _r): u(_u), v(_v), l(_l), r(_r) {}
};
const ll MOD = (ll)(1e9 + 7);
const int MAX_N = 100005;
const int MAX_M = MAX_N * 2;
int head[MAX_N], nt[MAX_M], pnt[MAX_M], total[MAX_N], ptr;
int visited[MAX_N];
inline void addedge(int x, int y) {
    pnt[ptr] = y; nt[ptr] = head[x]; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; head[y] = ptr++;
}
void dfs(int pos) {
    visited[pos] = true;
    for (int i = head[pos]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (visited[to]) {
            continue;
        }
        dfs(to);
        total[pos] += total[to];
    }
    ++total[pos];
}
int main() {
    int n, k, u, v, l, r;
    scanf("%d %d", &n, &k);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    vector<Edge> g;
    ptr = 0;
    memset(total, 0, sizeof total);
    memset(head, -1, sizeof head);
    memset(visited, false, sizeof visited);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d %d %d", &u, &v, &l, &r);
        addedge(u, v);
        g.push_back(Edge(u, v, l, r));
    }
    dfs(1);
    ll cnt = 0;
    vector<ll> arr;
    for (int i = 0; i < n - 1; ++i) {
        if (total[g[i].u] < total[g[i].v]) {
            swap(g[i].u, g[i].v);
        }
        arr.push_back(total[g[i].v] * (n - total[g[i].v]));
        cnt += arr.back() * g[i].l;
        g[i].r -= g[i].l;
        g[i].l = 0;
    }
    if (cnt > k) {
        printf("0\n");
        return 0;
    }
    k -= cnt;
    vector<vector<ll> > dp(n - 1, vector<ll>(k + 1, 0));
    dp[0][0] = 1;
    for (ll i = 1; i <= g[0].r && i * arr[0] <= k; ++i) {
        dp[0][i * arr[0]] = 1;
    }
    for (int i = 1; i <= k; ++i) dp[0][i] += dp[0][i - 1];
    for (ll i = 1; i < n - 1; ++i) {
        ll mx = ((ll)g[i].r + 1ll) * arr[i];
        for (ll j = 0; j <= k; ++j) {
            if (j >= mx) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - arr[i]] - dp[i - 1][j - mx]) % MOD;
                if (dp[i][j] < 0) {
                    dp[i][j] = (dp[i][j] + MOD) % MOD;
                }
            }
            else {
                dp[i][j] = dp[i - 1][j];
                if (j - arr[i] >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i][j - arr[i]]) % MOD;
                }
            }
        }
    }
    cout << dp[n - 2][k] << endl;
    return 0;
}
