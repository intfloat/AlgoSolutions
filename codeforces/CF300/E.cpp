#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int n, from, to;
    cin >> n;
    vector<vector<int> > g(n, vector<int>());
    FOR(i, n - 1) {
        cin >> from >> to;
        --from; --to;
        g[from].push_back(to);
    }
    vector<int> h(n), pts; h[0] = 0;
    queue<int> q; q.push(0);
    int leaves = 0;
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        pts.push_back(tp);
        leaves += (g[tp].size() == 0);
        FOR(i, g[tp].size()) {
            q.push(g[tp][i]);
            h[g[tp][i]] = h[tp] + 1;
        }
    }
    reverse(pts.begin(), pts.end());
    assert(pts.size() == n && pts[n - 1] == 0);
    vector<int> dp(n);
    // for max case
    FOR(i, n) {
        int u = pts[i];
        if (g[u].empty()) dp[u] = 1;
        else if (h[u] % 2 == 0) {
            dp[u] = INT_MAX;
            FOR(j, g[u].size()) dp[u] = min(dp[u], dp[g[u][j]]);
        }
        else {
            dp[u] = 0;
            FOR(j, g[u].size()) dp[u] += dp[g[u][j]];
        }
    }    
    cout << leaves - dp[0] + 1 << " ";

    // for min case
    FOR(i, n) {
        int u = pts[i];
        if (g[u].empty()) dp[u] = 1;
        else if (h[u] % 2 == 0) {
            dp[u] = 0;
            FOR(j, g[u].size()) dp[u] += dp[g[u][j]];
        }
        else {
            dp[u] = INT_MAX;
            FOR(j, g[u].size()) dp[u] = min(dp[u], dp[g[u][j]]);
        }
    }
    cout << dp[0] << endl;
    return 0;
}
