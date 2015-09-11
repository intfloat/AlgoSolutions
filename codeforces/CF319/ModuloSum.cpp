#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if (n >= m) {
        printf("YES\n");
        return 0;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        arr[i] %= m;
    }
    vector<vector<bool> > dp(2, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        bool ptr = i % 2;
        fill(dp[ptr].begin(), dp[ptr].end(), false);
        dp[ptr][arr[i]] = true;
        for (int j = 0; j < m; ++j) {
            if (dp[!ptr][j] || dp[!ptr][(j - arr[i] + m) % m]) {
                dp[ptr][j] = true;
            }
        }
        if (dp[ptr][0]) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
