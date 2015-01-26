#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MAX_N = 100005;
int p[MAX_N], dis[MAX_N], broke[MAX_N];

int main() {
    int n, m;
    vector<vector<tuple<int, bool> > > g(MAX_N);
    scanf("%d %d", &n, &m);
    FOR(i, m) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].emplace_back(make_tuple(y, z));
        g[y].emplace_back(make_tuple(x, z));
    }
    FOR(i, MAX_N) {
        p[i] = -1;
        dis[i] = broke[i] = MAX_N;
    }
    queue<int> q;
    bool inq[MAX_N];
    memset(inq, false, sizeof(inq));
    dis[1] = broke[1] = 0;
    q.push(1); inq[1] = true;
    while (!q.empty()) {
        int tp = q.front(); q.pop(); inq[tp] = false;
        FOR(i, g[tp].size()) {
            int to = get<0>(g[tp][i]);
            bool bad = !get<1>(g[tp][i]);
            if (dis[tp] + 1 < dis[to]) {
                dis[to] = dis[tp] + 1;
                broke[to] = broke[tp] + bad;
                p[to] = tp;
                if (!inq[to]) { q.push(to); inq[to] = true; }
            }
            else if (dis[tp] + 1 == dis[to] && broke[to] > broke[tp] + bad) {
                broke[to] = broke[tp] + bad;
                p[to] = tp;
                if (!inq[to]) { q.push(to); inq[to] = true; }
            }
        }
    }
    vector<tuple<int, int, bool> > res;
    set<tuple<int, int> > edges;
    int cur = n;
    while (p[cur] > 0) {
        edges.insert(make_tuple(min(cur, p[cur]), max(cur, p[cur])));
        cur = p[cur];
    }
    for (int i = 1; i <= n; ++i) {
        FOR(j, g[i].size()) {
            int to = get<0>(g[i][j]);
            int bad = !get<1>(g[i][j]);
            if (i > to) continue;
            if (bad && edges.find(make_tuple(i, to)) != edges.end()) res.emplace_back(make_tuple(i, to, true));
            else if (!bad && edges.find(make_tuple(i, to)) == edges.end()) res.emplace_back(make_tuple(i, to, false));
        }
    }
    printf("%d\n", res.size());
    FOR(i, res.size()) printf("%d %d %d\n", get<0>(res[i]), get<1>(res[i]), get<2>(res[i]));
    return 0;
}
