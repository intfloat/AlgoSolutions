#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const ll INF = (ll)(1e15);
ll dp[1 << 13][12][12];
inline void solve() {
    int n;
    scanf("%d", &n);
    vector<int> A(n), P(n);
    FOR(i, n) scanf("%d", &A[i]);
    FOR(i, n) scanf("%d", &P[i]);
    FOR(i, 1 << n) FOR(j, n) FOR(k, n) dp[i][j][k] = INF;
    vector<vector<int> > arr(n + 1);
    FOR(i, 1 << n) {
        arr[__builtin_popcount(i)].push_back(i);
    }
    if (n <= 2) {
        printf("0\n");
        return;
    }
    ll res = INF;
    FOR(q, n + 1) FOR(x, arr[q].size()) FOR(j, n) FOR(k, n) {
        int i = arr[q][x];
        if (!(i & (1 << j)) || !(i & (1 << k)) || j == k) {
            continue;
        }
        int cnt = q;
        if (cnt <= 2) {
            dp[i][j][k] = 0;
        }
        if (cnt > 1) {
            FOR(p, n) {
                if (i & (1 << p)) continue;
                dp[i | (1 << p)][p][j] = min(dp[i | (1 << p)][p][j], dp[i][j][k] + P[cnt] * (A[p] ^ A[j] ^ A[k]));
            }
        }
        if (q == n) {
            res = min(res, dp[i][j][k]);
        }
    }
    cout << res << endl;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
