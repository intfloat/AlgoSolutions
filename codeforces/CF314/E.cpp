#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll, int> point;
struct Edge {
    int x, y, w;
    Edge(int _x, int _y, int _w): x(_x), y(_y), w(_w) {}
};
const int MAX_N = 100100;
const int MAX_M = MAX_N * 2;
const ll INF = (ll)(1e14);
int head[MAX_N], pnt[MAX_M], nt[MAX_M], len[MAX_M], idx[MAX_M];
int n, m, s, t, ptr;
inline void addedge(int from, int to, int ww, int ii) {
    pnt[ptr] = to; len[ptr] = ww; idx[ptr] = ii; nt[ptr] = head[from]; head[from] = ptr++;
}
inline void init() {
    ptr = 0;
    memset(head, -1, sizeof head);
}
inline void dijkstra(const int from, vector<ll>& res) {
    vector<bool> ok(n, false);
    priority_queue<point, vector<point>, greater<point> > pq;
    pq.push(make_pair(0, from));
    res.resize(n);
    fill(res.begin(), res.end(), INF);
    res[from] = 0;
    while (!pq.empty()) {
        point tp = pq.top();
        pq.pop();
        ll dd = tp.first;
        int pos = tp.second;
        if (ok[pos]) {
            continue;
        }
        ok[pos] = true;
        for (int i = head[pos]; i != -1; i = nt[i]) {
            int to = pnt[i];
            if (!ok[to] && res[pos] + len[i] < res[to]) {
                res[to] = res[pos] + len[i];
                pq.push(make_pair(res[to], to));
            }
        }
    }
    return;
}
vector<bool> visited;
vector<int> dfn, low;
int cnt;
vector<bool> res;
void tarjan(int pos, int fe) {
    visited[pos] = true;
    dfn[pos] = low[pos] = cnt++;
    for (int i = head[pos]; i != -1; i = nt[i]) {
        if (fe == idx[i]) continue;
        int to = pnt[i];
        if (visited[to]) {
            low[pos] = min(low[pos], low[to]);
        }
        else {
            tarjan(to, idx[i]);
            low[pos] = min(low[pos], low[to]);
        }
    }
    if (fe >= 0 && dfn[pos] == low[pos]) {
        res[fe] = true;
    }
}
int main() {
    int a, b, wei;
    vector<ll> dis, rdis;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    --s; --t;
    vector<Edge> arr;
    FOR(i, m) {
        scanf("%d %d %d", &a, &b, &wei);
        --a; --b;
        arr.push_back(Edge(a, b, wei));
    }
    res.resize(m);
    fill(res.begin(), res.end(), false);
    // forward path
    init();
    FOR(i, arr.size()) {
        addedge(arr[i].x, arr[i].y, arr[i].w, i);
    }
    dijkstra(s, dis);
    assert(dis[t] < INF);
    // backward path
    init();
    FOR(i, arr.size()) {
        addedge(arr[i].y, arr[i].x, arr[i].w, i);
    }
    dijkstra(t, rdis);
    // find bridge
    init();
    FOR(i, arr.size()) {
        if (dis[arr[i].x] + rdis[arr[i].y] + arr[i].w == dis[t]) {
            addedge(arr[i].x, arr[i].y, arr[i].w, i);
            addedge(arr[i].y, arr[i].x, arr[i].w, i);
        }
    }
    visited.resize(n);
    fill(visited.begin(), visited.end(), false);
    dfn.resize(n); low.resize(n);
    cnt = 0; tarjan(s, -1);
    // FOR(i, n) {
    //     if (!visited[i]) {
    //         tarjan(i, -1);
    //     }
    // }
    FOR(i, m) {
        ll tmp = dis[t] - 1 - dis[arr[i].x] - rdis[arr[i].y];
        if (res[i]) printf("YES\n");
        else if (tmp >= 1) {
            assert(arr[i].w >= tmp);
            printf("CAN %d\n", arr[i].w - tmp);
        }
        else printf("NO\n");
    }
    return 0;
}
