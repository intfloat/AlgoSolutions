#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <utility>
#include <queue>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int INF = INT_MAX / 2;
vector<vector<pair<int, int> > > g;
vector<int> dis;
int N, ML, MD, from, to, w;

int spfa() {
    dis[0] = 0;
    queue<int> q;
    vector<bool> inq(N, false);
    inq[0] = true; q.push(0);
    vector<int> cnt(N, 0);
    ++cnt[0];

    while (!q.empty()) {
        int tp = q.front(); q.pop(); inq[tp] = false;
        FOR(i, g[tp].size()) {
            pair<int, int>& edge = g[tp][i];
            int idx = edge.first;
            if (dis[idx] > dis[tp] + edge.second) {
                dis[idx] = dis[tp] + edge.second;
                ++cnt[idx];
                if (cnt[idx] > N || dis[idx] < 0) return -1;
                if (!inq[idx]) { inq[idx] = true; q.push(idx); }
            }
        }
    }
    if (dis[N - 1] == INF) return -2;
    return dis[N - 1];
}

int main() {    
    scanf("%d %d %d", &N, &ML, &MD);
    g.resize(N); dis.resize(N);
    fill(dis.begin(), dis.end(), INF);   
    FOR(i, ML) {
        scanf("%d %d %d", &from, &to, &w);
        --from; --to;
        if (from > to) swap(from, to);
        g[from].push_back(make_pair(to, w));
    }
    FOR(i, MD) {
        scanf("%d %d %d", &from, &to, &w);
        --from; --to;
        if (from > to) swap(from, to);
        g[to].push_back(make_pair(from, -w));
    }
    for (int i = N - 1; i > 0; --i) g[i].push_back(make_pair(i - 1, 0));
    printf("%d\n", spfa());
    return 0;
}
