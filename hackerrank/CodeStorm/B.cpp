#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = INT_MAX / 10;
int dp[105][2];
inline void solve() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n + 2, 0);
    if (arr[1]) {
        dp[1][0] = INF;
        dp[1][1] = 0;
    }
    else {
        dp[1][0] = 0;
        dp[1][1] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        if (arr[i]) {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][0] = INF;
        }
        else {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = 1 + min(dp[i - 1][0], dp[i - 1][1]);
        }
    }
    printf("%d\n", min(dp[n][0], dp[n][1]));
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
