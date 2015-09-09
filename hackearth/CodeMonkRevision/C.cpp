#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 1000005;
int parent[MAX_N], N;
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
typedef pair<int, int> pii;
inline void solve() {
    int K, x, y;
    scanf("%d %d", &N, &K);
    init();
    vector<pii> ine;
    char type[10];
    FOR(i, K) {
        scanf("%d %s %d", &x, type, &y);
        if (type[0] == '!') {
            ine.push_back(make_pair(x, y));
        }
        else {
            int px = _find(x), py = _find(y);
            merge(px, py);
        }
    }
    FOR(i, ine.size()) {
        int px = _find(ine[i].first), py = _find(ine[i].second);
        if (px == py) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
