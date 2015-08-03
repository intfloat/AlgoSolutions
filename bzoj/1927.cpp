#include <stdio.h>
#include <vector>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
const int MAX_N = 1605;
const int MAX_M = 100000;
const int INF = INT_MAX / 2;
int S, T;
class MinCostMaxFlow {
public:
    int total, pv[MAX_N], pe[MAX_N], pnt[MAX_M];
    int flow[MAX_M], cost[MAX_M];
    int head[MAX_N], next[MAX_M];
    queue<int> q;
    bool visited[MAX_N];
    int dis[MAX_N];
    MinCostMaxFlow() {
        init();
    }
    void init() {
        total = 0;
        memset(head, -1, sizeof head);
    }
    void addedge(int f, int t, int cp, int cs) {
        next[total] = head[f]; head[f] = total; pnt[total] = t; flow[total] = cp; cost[total++] = cs;
        next[total] = head[t]; head[t] = total; pnt[total] = f; flow[total] = 0; cost[total++] = -cs;
    }
    int mincost(int& maxflow) {
        int mincost = 0;
        maxflow = 0;
        while (true) {
            memset(visited, false, sizeof(visited));
            for (int i = 0; i < MAX_N; ++i) {
                pv[i] = -1;
                dis[i] = INF;
            }
            while (!q.empty()) q.pop();
            dis[S] = 0; q.push(S); visited[S] = true;
            while (!q.empty()) {
                int cur = q.front(); q.pop(); visited[cur] = false;
                for (int i = head[cur]; i >= 0; i = next[i]) {
                    int b = pnt[i];
                    if (flow[i] > 0 && dis[b] > dis[cur]+cost[i]) {
                        dis[b] = dis[cur] + cost[i];
                        pv[b] = cur; pe[b] = i;
                        if (!visited[b]) { q.push(b); visited[b] = true; }
                    }
                }
            }
            if (dis[T] == INF) break;
            // find minimal flow on shortest
            int mn_flow = INF;
            for (int i = T; i != S; i = pv[i]) {
                mn_flow = min(mn_flow, flow[pe[i]]);
            }
            maxflow += mn_flow;
            mincost += mn_flow * dis[T];
            // update residual flow network
            for (int i = T; i != S; i = pv[i]) {
                flow[pe[i]] -= mn_flow;
                flow[pe[i] ^ 1] += mn_flow;
            }
        }
        return mincost;
    }
};
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> arr(n);
    S = 2 * n, T = 2 * n + 1;
    MinCostMaxFlow net;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        net.addedge(S, i * 2, 1, 0);
        net.addedge(i * 2 + 1, T, 1, 0);
        net.addedge(S, i * 2 + 1, 1, arr[i]);
    }
    int x, y, cc;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &x, &y, &cc);
        --x; --y;
        if (x > y) swap(x, y);
        net.addedge(2 * x, 2 * y + 1, 1, cc);
    }
    int flow = 0;
    int res = net.mincost(flow);
    printf("%d\n", res);
    return 0;
}
