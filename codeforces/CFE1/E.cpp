#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = INT_MAX / 10;
int dp[31][31][51];
int main() {
    for (int r = 1; r <= 30; ++r) {
        for (int c = 1; c <= 30; ++c) {
            for (int k = 0; k <= 50; ++k) {
                dp[r][c][k] = INF;
                if (r * c < k) dp[r][c][k] = INF;
                else if (k == 0) dp[r][c][k] = 0;
                else if (r * c == k) dp[r][c][k] = 0;
                else {
                    for (int nr = 1; nr < r; ++nr) {
                        for (int nk = 0; nk <= k; ++nk)
                            dp[r][c][k] = min(dp[r][c][k], dp[nr][c][nk] + dp[r - nr][c][k - nk] + c * c);
                    }
                    for (int nc = 1; nc < c; ++nc) {
                        for (int nk = 0; nk <= k; ++nk)
                            dp[r][c][k] = min(dp[r][c][k], dp[r][nc][nk] + dp[r][c - nc][k - nk] + r * r);
                    }
                }
            }
        }
    }
    int T, n, m, k;
    scanf("%d", &T);
    FOR(tt, T) {
        scanf("%d %d %d", &n, &m, &k);
        printf("%d\n", dp[n][m][k]);
    }
    return 0;
}
