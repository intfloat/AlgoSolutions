#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const int MAX_N = 100005;
ll dp[MAX_N][2], res[MAX_N];
int main() {
    int t, k, a, b;
    scanf("%d %d", &t, &k);
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1; i < MAX_N; ++i) {
        if (i - k >= 0) dp[i][1] = (dp[i - k][0] + dp[i - k][1]) % MOD;
        else dp[i][1] = 0;
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }
    res[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        res[i] = (res[i - 1] + dp[i][0] + dp[i][1]) % MOD;
    }
    for (int tt = 0; tt < t; ++tt) {
        scanf("%d %d", &a, &b);
        cout << (res[b] - res[a - 1] + MOD) % MOD << endl;
    }
    return 0;
}
