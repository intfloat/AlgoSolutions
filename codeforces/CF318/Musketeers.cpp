#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> point;
int main() {
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    set<point> g;
    vector<int> degree(n + 1, 0);
    FOR(i, m) {
        scanf("%d %d", &x, &y);
        if (x > y) swap(x, y);
        g.insert({x, y});
        ++degree[x];
        ++degree[y];
    }
    int res = INT_MAX;
    for (auto it = g.begin(); it != g.end(); ++it) {
        int a = (*it).first, b = (*it).second;
        for (int i = 1; i <= n; ++i) {
            if (i == a || i == b) continue;
            point e1 = {min(i, a), max(i, a)};
            point e2 = {min(i, b), max(i, b)};
            if (g.find(e1) != g.end() && g.find(e2) != g.end()) {
                res = min(res, degree[a] + degree[b] + degree[i] - 6);
            }
        }
    }
    if (res == INT_MAX) {
        printf("-1\n");
    }
    else {
        printf("%d\n", res);
    }
    return 0;
}
