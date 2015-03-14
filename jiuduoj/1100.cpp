#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MOD = 100000;
vector<int> pw;
vector<int> parent;
void preprocess(int up) {
    pw.resize(up);
    pw[0] = 1;
    for (int i = 1; i < pw.size(); ++i)
        pw[i] = (pw[i - 1] * 2) % MOD;
    return;
}

int _find(int root) {
    if (parent[root] == root) return root;
    parent[root] = _find(parent[root]);
    return parent[root];
}

void _union(int x, int y) {
    parent[x] = y;
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        preprocess(M);
        parent.resize(N);
        FOR(i, parent.size()) parent[i] = i;
        vector<vector<pair<int, int> > > g(N, vector<pair<int, int> >());
        FOR(i, M) {
            int x, y;
            cin >> x >> y;
            int rx = _find(x), ry = _find(y);
            if (rx != ry) {
                _union(rx, ry);
                g[x].push_back(make_pair(y, i));
                g[y].push_back(make_pair(x, i));
            }
        }
        vector<int> dis(N, 0);
        vector<bool> visited(N, false);
        queue<int> q;
        q.push(0); visited[0] = true;
        while (!q.empty()) {
            int tp = q.front(); q.pop();
            FOR(i, g[tp].size()) {
                int to = g[tp][i].first;
                int val = g[tp][i].second;
                if (!visited[to]) {
                    visited[to] = true;
                    dis[to] = (dis[tp] + pw[val]) % MOD;
                    q.push(to);
                }
            }
        }
        for (int i = 1; i < N; ++i) {
            if (!visited[i]) cout << -1 << endl;
            else cout << dis[i] << endl;
        }
    }
    return 0;
}
