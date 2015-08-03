
const int MAX_N = 500;
const int MAX_M = 50000;
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
