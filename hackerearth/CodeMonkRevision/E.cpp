#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> edge;
const int MAX_N = 1000005;
int parent[MAX_N], N, M;
inline void init() {
    for (int i = 0; i <= N; ++i) {
        parent[i] = i;
    }
}
int _find(int p) {
    if (p == parent[p]) return p;
    parent[p] = _find(parent[p]);
    return parent[p];
}
inline void merge(int p, int q) {
    parent[p] = q;
}
int main() {
    ll K;
    int x, y, w;
    scanf("%d %d %lld", &N, &M, &K);
    if (K + 1 < N) {
        printf("-1\n");
        return 0;
    }
    vector<edge> g;
    init();
    FOR(i, M) {
        scanf("%d %d %d", &x, &y, &w);
        g.push_back(make_pair(w, make_pair(x, y)));
    }
    int mst = 0;
    sort(g.begin(), g.end());
    ll cost = 0ll;
    int res = N;
    FOR(i, g.size()) {
        int px = _find(g[i].second.first), py = _find(g[i].second.second);
        if (px != py) {
            merge(px, py);
            ++mst;
            cost += g[i].first;
            if (res == N && cost + N - 1 - mst > K) {
                res = min(res, N - 1 - mst + 1);
            }
        }
    }
    if (mst < N - 1) printf("-1\n");
    else if (res == N) printf("0\n");
    else printf("%d\n", res);
    return 0;
}
