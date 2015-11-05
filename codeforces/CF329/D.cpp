#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 200005;
const int K = 19;
vector<int> g[MAX_N];
vector<ll> cost[MAX_N];
int fa[MAX_N][K], d[MAX_N], p[MAX_N];
ll wei[MAX_N];
inline void init() {
    FOR(i, MAX_N) p[i] = i;
}
inline int _find(int idx) {
    if (idx == p[idx]) return idx;
    p[idx] = _find(p[idx]);
    return p[idx];
}
void dfs(int cur, int pp, int dep) {
    fa[cur][0] = pp;
    d[cur] = dep;
    for (int i = 1; i < K; ++i) fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
    FOR(i, g[cur].size()) {
        int to = g[cur][i];
        if (to != pp) {
            wei[to] = cost[cur][i];
            if (wei[to] == 1) p[to] = _find(cur);
            dfs(to, cur, dep + 1);
        }
    }
}
inline int query(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    int diff = d[u] - d[v];
    for (int i = 0; diff && i < K; ++i) {
        if (diff & (1 << i)) {
            diff -= (1 << i);
            u = fa[u][i];
        }
    }
    if (u == v) return d[u];
    for (int i = K - 1; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i], v = fa[v][i];
        }
    }
    return d[fa[u][0]];
}
int main() {
    int n, m, u, v;
    ll ww;
    scanf("%d %d", &n, &m);
    init();
    vector<pii> edge;
    FOR(i, n - 1) {
        scanf("%d %d %I64d", &u, &v, &ww);
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u].push_back(ww);
        cost[v].push_back(ww);
        edge.push_back({u, v});
    }
    dfs(1, 1, 0);
    int type, a, b, ep;
    ll y, c;
    FOR(i, m) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d %I64d", &a, &b, &y);
            int df = query(a, b);
            while (y && d[a] > df) {
                int parent = _find(a);
                if (d[parent] <= df) break;
                a = fa[parent][0];
                y /= wei[parent];
            }
            while (y && d[b] > df) {
                int parent = _find(b);
                if (d[parent] <= df) break;
                b = fa[parent][0];
                y /= wei[parent];
            }
            printf("%I64d\n", y);
        }
        else {
            scanf("%d %I64d", &ep, &c);
            --ep;
            u = edge[ep].first, v = edge[ep].second;
            if (fa[u][0] == v) wei[u] = c;
            else wei[v] = c;
            if (c == 1) {
                if (d[u] > d[v]) p[u] = _find(v);
                else p[v] = _find(u);
            }
        }
    }
    return 0;
}
