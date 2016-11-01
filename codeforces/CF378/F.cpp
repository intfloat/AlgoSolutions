#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 200005;
const int MAX_M = MAX_N * 2;
const int K = 19;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], fa[MAX_N][K], d[MAX_N], ptr = 0;
int mx[MAX_N][K];
map<pii, int> wmp;
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
    mx[cur][0] = wmp[{cur, p}];
    d[cur] = dep;
    for (int i = 1; i < K; ++i) {
        fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
        mx[cur][i] = max(mx[cur][i - 1], mx[fa[cur][i - 1]][i - 1]);
    }
    for (int i = head[cur]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to != p) {
            dfs(to, cur, dep + 1);
        }
    }
}
inline int query(int u, int v) {
    int ret = 0;
    if (d[u] < d[v]) swap(u, v);
    int diff = d[u] - d[v];
    for (int i = 0; diff && i < K; ++i) {
        if (diff & (1 << i)) {
            diff -= (1 << i);
            ret = max(ret, mx[u][i]);
            u = fa[u][i];
        }
    }
    if (u == v) return ret;
    for (int i = K - 1; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) {
            ret = max(ret, mx[u][i]);
            ret = max(ret, mx[v][i]);
            u = fa[u][i], v = fa[v][i];
        }
    }
    ret = max(ret, mx[u][0]);
    ret = max(ret, mx[v][0]);
    return ret;
}

int ufa[MAX_N];
int _find(int x) {
    if (x == ufa[x]) return x;
    ufa[x] = _find(ufa[x]);
    return ufa[x];
}
inline void merge(int x, int y) {
    ufa[x] = y;
}
struct Edge {
    int u, v, wei, cost, i;
    bool in_mst;
    bool operator<(const Edge& that) const {
        return wei < that.wei;
    }
    Edge(int _u, int _v, int _w, int _c, int _i): u(_u), v(_v), wei(_w), cost(_c), i(_i), in_mst(false) {}
};
int main() {
    init();
    int n, m, u, v, S;
    scanf("%d %d", &n, &m);
    vector<int> w(m), c(m);
    FOR(i, m) scanf("%d", &w[i]);
    FOR(i, m) scanf("%d", &c[i]);
    FOR(i, n + 1) ufa[i] = i;
    vector<Edge> g;
    FOR(i, m) {
        scanf("%d %d", &u, &v);
        g.push_back(Edge(u, v, w[i], c[i], i + 1));
    }
    sort(g.begin(), g.end());
    wmp[{1, 1}] = 0;
    ll mn = (ll)(1e15), val = 0;
    int idx = -1;
    FOR(i, g.size()) {
        u = g[i].u;
        v = g[i].v;
        int ru = _find(u), rv = _find(v);
        if (ru != rv) {
            merge(ru, rv);
            g[i].in_mst = true;
            addedge(u, v);
            wmp[{u, v}] = g[i].wei;
            wmp[{v, u}] = g[i].wei;
            val += g[i].wei;
        }
    }
    scanf("%d", &S);
    dfs(1, 1, 0);
    mn = val;
    FOR(i, g.size()) {
        u = g[i].u;
        v = g[i].v;
        ll cur = 0;
        if (g[i].in_mst) {
            cur = val - S / g[i].cost;
        } else {
            cur = val + (g[i].wei - S / g[i].cost);
            cur -= query(u, v);
        }
        if (cur < mn) {
            mn = cur;
            idx = i;
        }
    }

    cout << mn << endl;
    // run Kruskal algorithm again
    g[idx].wei -= S / g[idx].cost;
    FOR(i, n + 1) ufa[i] = i;
    sort(g.begin(), g.end());
    FOR(i, g.size()) {
        u = g[i].u;
        v = g[i].v;
        int ru = _find(u), rv = _find(v);
        if (ru != rv) {
            merge(ru, rv);
            printf("%d %d\n", g[i].i, g[i].wei);
        }
    }
    return 0;
}
