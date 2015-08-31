#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    vector<vector<int> > dp(n, vector<int>(3, 0));
    FOR(i, n) {
        scanf("%d", &arr[i]);
    }
    int res = 0;
    FOR(i, n) {
        dp[i][arr[i] % 3] = arr[i];
        for (int j = i - 1; j >= 0; --j) FOR(k, 3) {
            if (dp[j][k] == 0) continue;
            int t = (k + arr[i]) % 3;
            dp[i][t] = max(dp[i][t], dp[j][k] + arr[i]);
        }
        res = max(res, dp[i][0]);
    }
    printf("%d\n", res);
    return 0;
}
