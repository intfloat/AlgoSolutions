#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 100005;
const int MAX_M = MAX_N * 2;
const int K = 18;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], fa[MAX_N][K], d[MAX_N], ptr = 0, n;
ll sm1[MAX_N], sm2[MAX_N], chd[MAX_N];
inline void addedge(int x, int y) {
    pnt[ptr] = y; nt[ptr] = head[x]; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; head[y] = ptr++;
}
inline void init() {
    ptr = 0;
    memset(head, -1, sizeof head);
    memset(sm1, 0, sizeof sm1);
    memset(sm2, 0, sizeof sm2);
    memset(chd, 0, sizeof chd);
}
// dfs(1, 1, 0), DO NOT set p = -1
void dfs(int cur, int p, int dep) {
    fa[cur][0] = p;
    d[cur] = dep;
    chd[cur] = sm1[cur] = 1;
    for (int i = 1; i < K; ++i) fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
    for (int i = head[cur]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to != p) {
            dfs(to, cur, dep + 1);
            chd[cur] += chd[to];
            sm1[cur] += sm1[to] + chd[to];
        }
    }

}
void dfs2(int cur, int p, int dep) {
    for (int i = head[cur]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to != p) {
            sm2[to] = sm2[cur] + sm1[cur] - 1 - (sm1[to] + chd[to]) + (n - chd[to]) + 1;
            dfs2(to, cur, dep + 1);
        }
    }
}
int tmp = -1;
inline int query(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    if (d[u] != d[v]) {
        int diff = d[u] - d[v] - 1;
        for (int i = 0; diff && i < K; ++i) {
            if (diff & (1 << i)) {
                diff -= (1 << i);
                u = fa[u][i];
            }
        }
        if (v == fa[u][0]) {
            tmp = u;
            return fa[u][0];
        }
        u = fa[u][0];
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
    int m, u, v;
    init();
    scanf("%d %d", &n, &m);
    FOR(i, n - 1) {
        scanf("%d %d", &u, &v);
        addedge(u, v);
    }
    dfs(1, 1, 0);
    sm2[1] = 1;
    dfs2(1, 1, 0);
    FOR(i, m) {
        scanf("%d %d", &u, &v);
        int ff = query(u, v);
        if (ff == u || ff == v) {
            int mid = abs(d[u] - d[v]) - 1;
            if (ff == v) swap(u, v);
            int cc = (n - chd[tmp]);
            double res = (sm2[tmp] - 1 - cc) / (double)cc + sm1[v] / (double)chd[v] + mid;
            printf("%.10lf\n", res);
        }
        else {
            int mid = d[u] + d[v] - 1 - 2 * d[ff];
            double res = sm1[u] / (double)chd[u] + sm1[v] / (double)chd[v] + mid;
            printf("%.10lf\n", res);
        }
    }
    return 0;
}
