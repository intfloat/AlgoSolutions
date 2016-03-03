#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const string MAGIC = "MAGIC";
const string NOTMAGIC = "NOT MAGIC";
const int MAX_N = 2505;
int g[MAX_N][MAX_N], n;
const int MAX_M = MAX_N * 2;
const int K = 13;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], fa[MAX_N][K], d[MAX_N], ptr = 0;
int mx[MAX_N][K], wei[MAX_M];
inline void addedge(int x, int y, int w) {
    pnt[ptr] = y; nt[ptr] = head[x]; wei[ptr] = w; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; wei[ptr] = w; head[y] = ptr++;
}
void dfs(int cur, int p, int dep, int ww) {
    fa[cur][0] = p;
    mx[cur][0] = ww;
    d[cur] = dep;
    for (int i = 1; i < K; ++i) {
        fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
        mx[cur][i] = max(mx[cur][i - 1], mx[fa[cur][i - 1]][i - 1]);
    }
    for (int i = head[cur]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to != p) {
            dfs(to, cur, dep + 1, wei[i]);
        }
    }
}
inline int query(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    int diff = d[u] - d[v];
    int res = 0;
    for (int i = 0; diff && i < K; ++i) {
        if (diff & (1 << i)) {
            diff -= (1 << i);
            res = max(res, mx[u][i]);
            u = fa[u][i];
        }
    }
    if (u == v) return res;
    for (int i = K - 1; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) {
            res = max(res, mx[u][i]);
            res = max(res, mx[v][i]);
            u = fa[u][i], v = fa[v][i];
        }
    }
    res = max(res, mx[u][0]);
    res = max(res, mx[v][0]);
    return res;
}
bool check() {
    FOR(i, n) {
        if (g[i][i] != 0) return false;
    }
    FOR(i, n) FOR(j, n) {
        if (g[i][j] != g[j][i]) return false;
    }
    return true;
}
int main() {
    memset(head, -1, sizeof head);
    scanf("%d", &n);
    FOR(i, n) FOR(j, n) scanf("%d", &g[i][j]);
    if (!check()) {
        cout << NOTMAGIC << endl;
        return 0;
    }
    vector<bool> visited(n, false);
    vector<int> dis(n, INT_MAX), to(n, 0);
    visited[0] = true;
    FOR(i, n) dis[i] = g[0][i];
    FOR(i, n - 1) {
        int mn = INT_MAX, pos = -1;
        FOR(j, n) {
            if (!visited[j] && dis[j] < mn) {
                mn = dis[j];
                pos = j;
            }
        }
        visited[pos] = true;
        addedge(to[pos], pos, mn);
        FOR(j, n) {
            if (!visited[j] && g[pos][j] < dis[j]) {
                to[j] = pos;
                dis[j] = g[pos][j];
            }
        }
    }
    dfs(0, 0, 0, 0);
    FOR(i, n) {
        for (int j = i + 1; j < n; ++j) {
            int ret = query(i, j);
            if (g[i][j] > ret) {
                cout << NOTMAGIC << endl;
                return 0;
            }
        }
    }
    cout << MAGIC << endl;
    return 0;
}
