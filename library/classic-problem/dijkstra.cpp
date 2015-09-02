#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> point;
const int MAX_N = 100100;
const int MAX_M = 500100;
const ll INF = (ll)(1e14);
int head[MAX_N], pnt[MAX_M], nt[MAX_M], len[MAX_M];
int n, ptr;
inline void addedge(int from, int to, int ww) {
    pnt[ptr] = to; len[ptr] = ww; nt[ptr] = head[from]; head[from] = ptr++;
    pnt[ptr] = from; len[ptr] = ww; nt[ptr] = head[to]; head[to] = ptr++;
}
inline void init() {
    ptr = 0;
    memset(head, -1, sizeof head);
}
inline void dijkstra(const int from, vector<ll>& res) {
    vector<bool> ok(n + 1, false);
    priority_queue<point, vector<point>, greater<point> > pq;
    pq.push(make_pair(0, from));
    res.resize(n + 1);
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
int main() {
    return 0;
}
