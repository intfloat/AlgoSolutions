#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const ll INF = static_cast<ll>(1e15);
int main(){ 
    int n, m;
    cin >> m >> n;
    vector<ll> h(n);
    FOR(i, n) cin >> h[i];
    reverse(h.begin(), h.end());
    vector<vector<ll> > dp(n + 5, vector<ll>(m + 5, INF));
    dp[0][0] = 0;
    FOR(i, n + 1) FOR(j, m + 1) {
        if (dp[i][j] >= INF) continue;
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        if (3 * (j + 1) <= i + 2) 
            dp[i + 2][j + 1] = min(dp[i + 2][j + 1], dp[i][j] + (h[i] - h[i + 1]) * (h[i] - h[i + 1]));
    }
    cout << dp[n][m] << endl;
    return 0;
}
