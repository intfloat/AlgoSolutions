#include <bits/stdc++.h>
using namespace std;

int S, T;
const int INF = INT_MAX / 2;
const int MAX_N = 60000;
class MaxFlow {
private:
    int nt[MAX_N], head[MAX_N], pnf[MAX_N], pnt[MAX_N], flow[MAX_N], ptr, pv[MAX_N], mn[MAX_N];
    bool visited[MAX_N];
public:
    MaxFlow() {
        init();
    }
    void init() {
        ptr = 0;
        memset(head, -1, sizeof head);
    }
    void addedge(int from, int to, int c) {
        nt[ptr] = head[from]; head[from] = ptr; pnf[ptr] = from; pnt[ptr] = to; flow[ptr++] = c;
        nt[ptr] = head[to]; head[to] = ptr; pnf[ptr] = to; pnt[ptr] = from; flow[ptr++] = 0;
    }
    int maxflow() {
        int res = 0;
        while (true) {
            memset(visited, false, sizeof visited);
            memset(pv, -1, sizeof pv);
            memset(mn, -1, sizeof mn);
            queue<int> q; q.push(S); visited[S] = true; mn[S] = INF;
            while (!q.empty()) {
                int tp = q.front(); q.pop();
                for (int i = head[tp]; i != -1; i = nt[i]) {
                    if (flow[i] == 0) continue;
                    int to = pnt[i];
                    if (visited[to]) continue;
                    pv[to] = i; visited[to] = true; q.push(to); mn[to] = min(mn[tp], flow[i]);
                }
            }
            if (mn[T] <= 0) break;
            res += mn[T];
            int cur = pv[T];
            while (cur != -1) {
                flow[cur] -= mn[T]; flow[cur ^ 1] += mn[T];
                cur = pv[pnf[cur]];
            }
        }
        return res;
    }
};
