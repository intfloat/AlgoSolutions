#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = (ll)(1e9 + 7);
const int MAX_N = 100005;
const int MAX_M = MAX_N * 2;
const int K = 18;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], fa[MAX_N][K], d[MAX_N], ptr = 0;
inline void addedge(int x, int y) {
    pnt[ptr] = y; nt[ptr] = head[x]; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; head[y] = ptr++;
}
inline void init() {
    ptr = 0;
    memset(head, -1, sizeof head);
}
void dfs(int cur, int p, int dep) {
    fa[cur][0] = p;
    d[cur] = dep;
    for (int i = 1; i < K; ++i) fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
    for (int i = head[cur]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to != p) {
            dfs(to, cur, dep + 1);
        }
    }
}
inline int query(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    int diff = d[u] - d[v];
    for (int i = 0; diff && i < K; ++i) {
        if (diff & (1 << i)) {
            diff -= (1 << i);
            u = fa[u][i];
        }
    }
    if (u == v) return u;
    for (int i = K - 1; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i], v = fa[v][i];
        }
    }
    return fa[u][0];
}
int start[MAX_N], tt[MAX_N], top[MAX_N];
set<pii> st;
vector<ll> twos(MAX_N * 10);
ll res = 0ll;
void solve(int cur, int p) {
    for (int i = head[cur]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to == p) continue;
        solve(to, cur);
        if (st.find({to, cur}) != st.end()) {
            int cnt = start[to] - top[to];
            res = (res + twos[cnt] - 1) % MOD;
            res = (res + MOD) % MOD;
        }
        else if (st.find({cur, to}) != st.end()) {
            int cnt = tt[to] - top[to];
            res = (res + twos[cnt] - 1) % MOD;
            res = (res + MOD) % MOD;
        }
        start[cur] += start[to];
        tt[cur] += tt[to];
        top[cur] += top[to];
    }
}
int main() {
    int N, x, y, type;
    init();
    memset(start, 0, sizeof start);
    memset(tt, 0, sizeof tt);
    memset(top, 0, sizeof top);
    scanf("%d", &N);
    twos[0] = 1;
    for (int i = 1; i < twos.size(); ++i) {
        twos[i] = (twos[i - 1] * 2ll) % MOD;
    }
    for (int i = 0; i < N - 1; ++i) {
        scanf("%d %d %d", &x, &y, &type);
        addedge(x, y);
        if (type) {
            st.insert({y, x});
        }
    }
    dfs(1, 1, 0);
    int KK;
    scanf("%d", &KK);
    vector<int> arr(KK + 1);
    arr[0] = 1;
    for (int i = 1; i <= KK; ++i) scanf("%d", &arr[i]);
    for (int i = 0; i + 1 <= KK; ++i) {
        int from = arr[i], to = arr[i + 1];
        if (from == to) continue;
        int anc = query(from, to);
        ++start[from]; ++tt[to]; ++top[anc];
    }
    solve(1, -1);
    cout << res << endl;
    return 0;
}
