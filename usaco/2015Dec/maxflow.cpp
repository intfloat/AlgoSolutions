#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 50005;
const int MAX_M = MAX_N * 2;
const int K = 17;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], fa[MAX_N][K], d[MAX_N], ptr = 0;
int sm[MAX_N];
inline void addedge(int x, int y) {
    pnt[ptr] = y; nt[ptr] = head[x]; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; head[y] = ptr++;
}
inline void init() {
    ptr = 0;
    memset(sm, 0, sizeof sm);
    memset(head, -1, sizeof head);
}
// dfs(1, 1, 0), DO NOT set p = -1
void dfs(int cur, int p, int dep) {
    fa[cur][0] = p;
    d[cur] = dep;
    for (int i = 1; i < K; ++i) fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
    for (int i = head[cur]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to != p) {
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
    if (u == v) return u;
    for (int i = K - 1; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i], v = fa[v][i];
        }
    }
    return fa[u][0];
}
void dfs2(int cur) {
    for (int i = head[cur]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to != fa[cur][0]) {
            dfs2(to);
            sm[cur] += sm[to];
        }
    }
}
int main() {
    init();
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    int n, k, u, v;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &u, &v);
        addedge(u, v);
    }
    dfs(1, 1, 0);
    for (int i = 0; i < k; ++i) {
        scanf("%d %d", &u, &v);
        int f = query(u, v);
        ++sm[u]; ++sm[v]; --sm[f];
        if (fa[f][0] != f) --sm[fa[f][0]];
    }
    dfs2(1);
    int res = *max_element(sm + 1, sm + n + 1);
    printf("%d\n", res);
    return 0;
}
