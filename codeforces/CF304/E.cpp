#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int S, T, ptr = 0;
const int INF = INT_MAX / 2;
int nt[2000], head[2000], pnf[2000], pnt[2000], flow[2000];
vector<int> pv, mn;
vector<bool> visited;
void addedge(int from, int to, int c) {
    nt[ptr] = head[from]; head[from] = ptr; pnf[ptr] = from; pnt[ptr] = to; flow[ptr++] = c;
    nt[ptr] = head[to]; head[to] = ptr; pnf[ptr] = to; pnt[ptr] = from; flow[ptr++] = 0;
}
int maxflow() {
    int res = 0;
    while (true) {
        fill(visited.begin(), visited.end(), false);
        fill(pv.begin(), pv.end(), -1);
        fill(mn.begin(), mn.end(), -1);
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
int main() {
    int n, m, u, v, from, to;
    cin >> n >> m;
    visited.resize(3 * n); pv.resize(3 * n); mn.resize(3 * n);
    memset(head, -1, sizeof head);
    vector<int> a(n), b(n);
    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];
    S = 2 * n; T = 2 * n + 1;
    FOR(i, n) {        
        addedge(S, i, a[i]);
        addedge(i + n, T, b[i]);
    }
    FOR(i, m) {
        cin >> u >> v;
        --u; --v;
        addedge(u, v + n, a[u]);
        addedge(v, u + n, a[v]);
    }
    FOR(i, n) addedge(i, i + n, a[i]);
    int s1 = accumulate(a.begin(), a.end(), 0);
    int s2 = accumulate(b.begin(), b.end(), 0);
    if (s1 != s2) {
        cout << "NO" << endl;
        return 0;
    }
    int total = maxflow();
    if (total != s1) {
        cout << "NO" << endl; return 0;
    }
    cout << "YES" << endl;
    vector<vector<int> > res(n, vector<int>(n, 0));
    for (int i = 0; i < ptr; i += 2) {
        from = pnf[i]; to = pnt[i];
        if (from >= S || to >= S) continue;
        res[from][to - n] = flow[i ^ 1];
    }    
    FOR(i, res.size()) {
        FOR(j, res[i].size()) cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
