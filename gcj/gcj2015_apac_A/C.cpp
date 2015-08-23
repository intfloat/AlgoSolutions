#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> point;
const ll INF = (ll)1e14;
struct Edge {
    int from, to, idx;
    ll wei;
    Edge(int _f, int _t, ll _w, int _i): from(_f), to(_t), wei(_w), idx(_i) {}
};
void solve() {
    int n, m, x, y;
    ll w;
    scanf("%d %d", &n, &m);
    vector<Edge> arr;
    ll g[105][105];
    FOR(i, n) FOR(j, n) {
        if (i == j) g[i][j] = 0;
        else g[i][j] = INF;
    }
    FOR(i, m) {
        cin >> x >> y >> w;
        g[x][y] = min(g[x][y], w);
        g[y][x] = min(g[y][x], w);
        arr.push_back(Edge(x, y, w, i));
    }
    ll dis[105][105];
    FOR(i, n) FOR(j, n) {
        dis[i][j] = g[i][j];
    }
    FOR(k, n) FOR(i, n) FOR(j, n) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
    vector<bool> ok(m, false);
    FOR(i, m) {
        int f = arr[i].from, t = arr[i].to;
        ll w = arr[i].wei;
        FOR(j, n) FOR(k, n) {
            if (ok[i] || dis[j][k] == dis[j][f] + w + dis[t][k]) {
                ok[i] = true;
                break;
            }
        }
        if (!ok[i]) {
            cout << i << endl;
        }
    }
    return;
}
int main() {
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ":" << endl;
        solve();
    }
    return 0;
}
