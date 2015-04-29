#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MAX_N = 100005;
map<int, int> m[MAX_N];
int parent[MAX_N], color[MAX_N];
bool visited[MAX_N];
vector<vector<int> > g;

void solve() {
    int N, x, y, type, node, ncolor;
    scanf("%d", &N);
    g.resize(N);
    FOR(i, N) g[i].clear();
    FOR(i, N - 1) {
        scanf("%d %d", &x, &y);
        --x; --y;
        g[x].push_back(y); g[y].push_back(x);
    }
    FOR(i, N) { color[i] = 0; visited[i] = false; }
    FOR(i, N) m[i].clear();
    // bfs
    visited[0] = true; parent[0] = -1;
    queue<int> q; q.push(0);
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        FOR(i, g[tp].size()) {
            int to = g[tp][i];
            if (visited[to]) continue;
            visited[to] = true; parent[to] = tp;
            q.push(to); ++m[tp][0];
        }
    }

    int cc = 1, query;
    scanf("%d", &query);
    FOR(i, query) {
        scanf("%d", &type);
        if (type == 1) printf("%d\n", cc);
        else {
            scanf("%d %d", &node, &ncolor);            
            --node;
            if (ncolor == color[node]) continue;
            int pcnt = m[node][color[node]], ncnt = m[node][ncolor];
            int pt = parent[node];
            if (node != 0) {
                --m[pt][color[node]];
                ++m[pt][ncolor];
            }
            if (node != 0 && color[pt] == color[node]) ++pcnt;
            else if (node != 0 && color[pt] == ncolor) ++ncnt;
            color[node] = ncolor;
            cc += pcnt - ncnt;
        }
    }
    return;
}

int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        printf("Case #%d:\n", tt + 1);        
        solve();
    }
    return 0;
}
