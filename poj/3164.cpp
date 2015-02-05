// Minimum Spanning Tree for directed graph, chu-liu edmonds algorithm
#include <limits.h>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
struct Edge {
    int from, to;
    double wei;    
    Edge() {}
};

pair<double, double> points[105];
Edge edges[105 * 105];
int pre[105], mp[105];
double mn[105];
int visited[105];
double res;
const int INF = INT_MAX / 2;

bool chu_liu_edmonds(int root, int NV, int NE) {    
    while (true) {
        FOR(i, 105) {
            pre[i] = mp[i] = -1;
            mn[i] = INF;
            visited[i] = -1;
        }        
        FOR(i, NE) {
            int from = edges[i].from, to = edges[i].to;
            double wei = edges[i].wei;
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
            double wei = edges[i].wei;
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
    double w;
    while (scanf("%d %d", &N, &M) != EOF) {        
        res = 0;
        FOR(i, N) {
            cin >> points[i].first >> points[i].second;            
        }
        int ptr = 0;
        FOR(i, M) {
            if (scanf("%d %d", &x, &y) == EOF) continue;
            --x; --y;
            if (x == y || y == 0) continue;
            double dx = points[x].first - points[y].first;
            double dy = points[x].second - points[y].second;
            w = sqrt(dx * dx + dy * dy);
            edges[ptr].from = x; edges[ptr].to = y; edges[ptr++].wei = w;            
        }
        bool ok = chu_liu_edmonds(0, N, ptr);
        if (ok) printf("%.2f\n", res);
        else printf("poor snoopy\n");
    }
    return 0;
}
