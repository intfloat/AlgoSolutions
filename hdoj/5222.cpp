#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

vector<int> p, rk;

int _find(int pos) {
    if (pos == p[pos]) return pos;
    p[pos] = _find(p[pos]);
    return p[pos];
}

void _union(int x, int y) {
    if (rk[x] < rk[y]) {
        p[x] = y;
        rk[y] += rk[x];
    }
    else {
        p[y] = x;
        rk[x] += rk[y];
    }
}

void solve() {
    int n, m1, m2, u, v, pu, pv;
    scanf("%d %d %d", &n, &m1, &m2);
    p.resize(n); rk.resize(n);
    FOR(i, rk.size()) rk[i] = 1;
    FOR(i, p.size()) p[i] = i;
    bool ok = false;
    FOR(i, m1) {
        scanf("%d %d", &u, &v);
        --u; --v;
        pu = _find(u); pv = _find(v);
        if (pu == pv) ok = true;
        else _union(pu, pv);
    }
    if (ok) {
        FOR(i, m2) scanf("%d %d", &u ,&v);
        printf("YES\n");
        return;
    }
    vector<vector<int> > g(n, vector<int>());
    vector<int> ind(n, 0);
    FOR(i, m2) {
        scanf("%d %d", &u, &v);
        --u; --v;
        u = p[u]; v = p[v];
        // in the same connected component
        if (u == v) ok = true;
        else {
            g[u].push_back(v);
            ++ind[v];
        }
    }
    vector<bool> visited(n, false);
    queue<int> q;
    FOR(i, n) {
        if (!ind[i]) {
            q.push(i);
            visited[i] = true;
        }
    }
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        FOR(i, g[tp].size()) {
            int to = g[tp][i];
            --ind[to];
            if (ind[to] <= 0 && !visited[to]) {
                q.push(to);
                visited[to] = true;
            }
        }
    }
    int cnt = accumulate(visited.begin(), visited.end(), 0);    
    if (ok || (cnt != n)) printf("YES\n");
    else printf("NO\n");
    return;
}

int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) solve();
    return 0;
}
