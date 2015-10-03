#include <tuple>
#include <stdio.h>
#include <cassert>
#include <vector>
#include <queue>
#include <limits.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const int MAX_N = 1005;
int main() {
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);
    int src, dest, N;
    vector<vector<tuple<int, int, int> > > g;
    scanf("%d %d %d", &src, &dest, &N);
    g.resize(MAX_N);
    FOR(i, N) {
        int cost, city;
        vector<int> pos;
        scanf("%d %d", &cost, &city);
        pos.resize(city);
        FOR(j, city)
            scanf("%d", &pos[j]);
        for (int j = 0; j < city; ++j)
        for (int k = j + 1; k < city; ++k)
            g[pos[j]].emplace_back(make_tuple(pos[k], cost, k - j));
    }

    // <cost, Number of edges>
    queue<int> q;
    const ll INF = static_cast<ll>(1e17);
    vector<tuple<ll, int> > dis(MAX_N);
    FOR(i, dis.size()) dis[i] = make_tuple(INF, INT_MAX / 2);
    vector<bool> inq(MAX_N, false);
    q.push(src); dis[src] = make_tuple(0, 0); inq[src] = true;
    // run spfa algorithm to find shortest path
    while (!q.empty()) {
        int tp = q.front(); q.pop(); inq[tp] = false;
        ll nc = get<0>(dis[tp]); 
        int nl = get<1>(dis[tp]);        
        for (int i = 0; i < g[tp].size(); ++i) {
            int to = get<0>(g[tp][i]);
            ll cost = get<1>(g[tp][i]);
            int len = get<2>(g[tp][i]);
            tuple<ll, int> nt = make_tuple(nc + cost, nl + len);
            if (nt < dis[to]) {
                dis[to] = nt;
                if (!inq[to]) { q.push(to); inq[to] = true; }
            }
        }
    }
    if (get<0>(dis[dest]) == INF)
        printf("-1 -1\n");    
    else printf("%lld %d\n", get<0>(dis[dest]), get<1>(dis[dest]));
    return 0;
}
