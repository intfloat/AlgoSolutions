#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 100005;
const int MAX_M = MAX_N * 2;
const int K = 18;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], fa[MAX_N][K], d[MAX_N], ptr = 0;
vector<int> cnt[MAX_N];
vector<int> fn[MAX_N][K];
inline void addedge(int x, int y) {
    pnt[ptr] = y; nt[ptr] = head[x]; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; head[y] = ptr++;
}
inline void init() {
    ptr = 0;
    memset(head, -1, sizeof head);
}
inline void merge(vector<int>& v1, const vector<int>& v2) {
    FOR(i, v2.size()) v1.push_back(v2[i]);
    sort(v1.begin(), v1.end());
    int len = unique(v1.begin(), v1.end()) - v1.begin();
    v1.resize(min(len, 10));
}
// dfs(1, 1, 0), DO NOT set p = -1
void dfs(int cur, int p, int dep) {
    fa[cur][0] = p;
    d[cur] = dep;
    fn[cur][0] = cnt[cur];
    merge(fn[cur][0], cnt[p]);
    for (int i = 1; i < K; ++i) {
        fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
        fn[cur][i] = fn[cur][i - 1];
        merge(fn[cur][i], fn[fa[cur][i - 1]][i - 1]);
    }
    for (int i = head[cur]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to != p) {
            dfs(to, cur, dep + 1);
        }
    }
}
vector<int> res;
inline void query(int u, int v, int a) {
    res.clear();
    if (d[u] < d[v]) swap(u, v);
    int diff = d[u] - d[v];
    for (int i = 0; diff && i < K; ++i) {
        if (diff & (1 << i)) {
            merge(res, fn[u][i]);
            diff -= (1 << i);
            u = fa[u][i];
        }
    }
    if (u == v) {
        merge(res, cnt[u]);
        if ((int)res.size() > a) res.resize(a);
        printf("%d ", (int)res.size());
        FOR(i, res.size()) printf("%d ", res[i]);
        printf("\n");
        return;
    }
    for (int i = K - 1; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) {
            merge(res, fn[u][i]);
            merge(res, fn[v][i]);
            u = fa[u][i], v = fa[v][i];
        }
    }
    merge(res, fn[u][0]);
    merge(res, fn[v][0]);
    if ((int)res.size() > a) res.resize(a);
    printf("%d ", (int)res.size());
    FOR(i, res.size()) printf("%d ", res[i]);
    printf("\n");
}

int main() {
    init();
    int n, m, q, u, v, c, a;
    scanf("%d %d %d", &n, &m, &q);
    FOR(i, n - 1) {
        scanf("%d %d", &u, &v);
        addedge(u, v);
    }
    FOR(i, m) {
        scanf("%d", &c);
        cnt[c].push_back(i + 1);
    }
    FOR(i, n) {
        sort(cnt[i + 1].begin(), cnt[i + 1].end());
        if (cnt[i + 1].size() > 10) {
            cnt[i + 1].resize(10);
        }
    }
    dfs(1, 1, 0);
    FOR(i, q) {
        scanf("%d %d %d", &u, &v, &a);
        query(u, v, a);
    }
    return 0;
}
