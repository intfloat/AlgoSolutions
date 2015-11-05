#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 10005;
const int MAX_M = MAX_N * 2;
const int K = 18;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], fa[MAX_N][K], d[MAX_N], ptr = 0;
inline void addedge(int x, int y) {
    pnt[ptr] = y; nt[ptr] = head[x]; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; head[y] = ptr++;
}
inline void init() {
    ptr = 0;
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
int main() {
    return 0;
}
