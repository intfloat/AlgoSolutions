#include <limits.h>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
struct Edge {
    int from, to;
    int wei;    
    Edge() {}
};

const int MAX_N = 105;
pair<int, int> points[MAX_N];
Edge edges[MAX_N * MAX_N + MAX_N];
int pre[MAX_N], mp[MAX_N];
int mn[MAX_N];
int visited[MAX_N];
long long res;
const int INF = (int)1e9;

bool chu_liu_edmonds(int root, int NV, int NE) {    
    while (true) {
        FOR(i, NV) {
            pre[i] = mp[i] = -1;
            mn[i] = INF;
            visited[i] = -1;
        }        
        FOR(i, NE) {
            int from = edges[i].from, to = edges[i].to;
            int wei = edges[i].wei;
            if (wei < mn[to] && to != root && from != to) { pre[to] = from; mn[to] = wei; }
        }
        int cnt = 0;
        // assert(pre[root] == -1);
        FOR(i, NV) {
            if (i != root && pre[i] == -1) return false; // unreachable node
        }
        
        // find if there is any circle in the graph
        FOR(i, NV) {         
            if (visited[i] != -1) continue;
            int cur = pre[i]; visited[i] = i;
            assert(cur != i);
            while (true) {
                if (cur == -1 || visited[cur] != -1) break;
                visited[cur] = i;
                cur = pre[cur];
            }
            if (cur == -1) continue;
            else if (visited[cur] == i) {                
                while (mp[cur] == -1) {
                    mp[cur] = cnt;
                    cur = pre[cur];
                }
                ++cnt;
            }
        }
        FOR(i, NV) { if (i != root) res += mn[i]; }        
        if (cnt == 0) return true; // no circle
        FOR(i, NV) {
            // res += mn[i];
            if (mp[i] == -1) mp[i] = cnt++;
        }

        // contract the graph
        int ptr = 0;
        FOR(i, NE) {
            int from = edges[i].from;
            int to = edges[i].to;
            int wei = edges[i].wei;
            if (mp[from] != mp[to]) {
                edges[ptr].from = mp[from];
                edges[ptr].to = mp[to];
                edges[ptr++].wei = edges[i].wei - mn[to];
            }
        }
        root = mp[root];
        NE = ptr; NV = cnt;
    }
}

int main() {
    int N, M, x, y;
    int w;
    while (cin >> N >> M) {        
        res = 0;
        FOR(i, N) {
            cin >> points[i].first >> points[i].second;            
        }        
        int ptr = 0;
        FOR(i, M) {
            cin >> x >> y;
            --x; --y;
            if (x == y) continue;
            int dx = points[x].first - points[y].first;
            int dy = points[x].second - points[y].second;
            w = abs(dx) + abs(dy);
            edges[ptr].from = x; edges[ptr].to = y; edges[ptr++].wei = w;            
        }
        FOR(i, N) {
            edges[ptr].from = N; edges[ptr].to = i; edges[ptr++].wei = INF / 2;
        }
        bool ok = chu_liu_edmonds(N, N + 1, ptr);
        if (ok && res < INF) cout << res - INF / 2 << endl;
        else cout << "Poor" << endl;
    }
    return 0;
}
