#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const int INF = 3500;
int main() {
    int n, m, u, v, to, s1, s2, t1, t2, len1, len2;
    scanf("%d %d", &n, &m);
    vector<vector<int> > g(n, vector<int>());
    FOR(i, m) {
        scanf("%d %d", &u, &v);
        --u; --v;
        g[u].push_back(v); g[v].push_back(u);
    }
    scanf("%d %d %d %d %d %d", &s1, &t1, &len1, &s2, &t2, &len2);
    --s1; --s2; --t1; --t2;
    vector<vector<int> > dis(n, vector<int>(n, INF));
    vector<bool> visited(n);
    // bfs to get all pair shortest path
    FOR(i, n) {
        fill(visited.begin(), visited.end(), false);
        visited[i] = true; dis[i][i] = 0;
        queue<int> q; q.push(i);
        while (!q.empty()) {
            int tp = q.front(); q.pop();
            FOR(j, g[tp].size()) {
                to = g[tp][j];
                if (!visited[to]) {
                    visited[to] = true;
                    dis[i][to] = dis[i][tp] + 1;
                    q.push(to);
                }
            }
        }
    }
    if (dis[s1][t1] > len1 || dis[s2][t2] > len2) {
        cout << -1 << endl;
        return 0;
    }
    int res = dis[s1][t1] + dis[s2][t2];
    FOR(i, n) FOR(j, n) {
        int val = dis[s1][i] + dis[i][j] + dis[j][t1];
        int d21 = dis[i][j] + dis[s2][i] + dis[j][t2];
        int d22 = dis[i][j] + dis[s2][j] + dis[i][t2];
        if (val <= len1 && d21 <= len2) res = min(res, val + d21 - dis[i][j]);
        if (val <= len1 && d22 <= len2) res = min(res, val + d22 - dis[i][j]);
    }
    res = m - res;
    cout << res << endl;
    return 0;
}
