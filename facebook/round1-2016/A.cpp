#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// 1: any
// 4: increase, <= 10
// 2: a < b && b - a <= 30
// 3: a < b && b < c && b - a <= 20 && c - b <= 20 && !(b - a > 10 && c - b > 10)
inline void solve() {
    int N;
    scanf("%d", &N);
    vector<int> arr(N + 1), dp(N + 1);
    FOR(i, N) scanf("%d", &arr[i + 1]);
    dp[0] = 0;
    int a, b, c, d;
    for (int i = 1; i <= N; ++i) {
        dp[i] = 3 + dp[i - 1];
        if (i >= 2) {
            a = arr[i - 1], b = arr[i];
            if (a < b && b - a <= 30) {
                dp[i] = min(dp[i], dp[i - 2] + 2);
            }
        }
        if (i >= 3) {
            a = arr[i - 2], b = arr[i - 1], c = arr[i];
            if (a < b && b < c && b - a <= 20 && c - b <= 20 && !((b - a > 10) && (c - b > 10))) {
                dp[i] = min(dp[i], dp[i - 3] + 1);
            }
        }
        if (i >= 4) {
            a = arr[i - 3], b = arr[i - 2], c = arr[i - 1], d = arr[i];
            if (a < b && b - a <= 10 && b < c && c - b <= 10 && c < d && d - c <= 10) {
                dp[i] = min(dp[i], dp[i - 4]);
            }
        }
    }
    printf("%d\n", dp[N]);
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
