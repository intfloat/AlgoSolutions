/**************************************************************
    Problem: 1070
    User: BananaTree
    Language: C++
    Result: Accepted
    Time:924 ms
    Memory:6044 kb
****************************************************************/
 
#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>
 
using namespace std;
 
const int MAX_N = 150000;
const int INF = INT_MAX / 2;
int S, T;
 
class MinCostMaxFlow {
public:
    int total, pv[MAX_N], pe[MAX_N], pnt[MAX_N];
    int flow[MAX_N], cost[MAX_N];
    int head[MAX_N], next[MAX_N];
    queue<int> q;
    bool visited[MAX_N];
    int dis[MAX_N];
    MinCostMaxFlow() {
        total = 0;
        for (int i = 0; i < MAX_N; ++i) {
            head[i] = -1;           
        }
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
                for (int i = head[cur]; i >=0; i = next[i]) {
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
    MinCostMaxFlow net;
    int m, n;
    int arr[65][15];
    scanf("%d%d", &m, &n);
    S = 0; T = 2 * n + n * m + 1;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {       
        scanf("%d", &arr[i][j]);        
    }
    for (int i = 1; i <= n; ++i) {
        net.addedge(S, i, INF, 0);
        for (int j = 1; j <= m; ++j) {
            int curt = n + (i-1)*m + j;
            net.addedge(i, curt, 1, 0);
            for (int k = 1; k <= n; ++k) {
                net.addedge(curt, n + n * m + k, 1, arr[k][j]*i);
            }
        }
    }
    for (int i = 1; i <= n; ++i) net.addedge(n + n * m + i, T, 1, 0);
    int maxflow;
    int total = net.mincost(maxflow);
    // printf("mincost: %d\n", total);
    // printf("maxflow: %d\n", maxflow);    
    double res = total / (n * 1.0);
    printf("%.2f\n", res);
    return 0;
}