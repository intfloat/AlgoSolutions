#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 100005;
int dp1[27][MAX_N], dp2[27][MAX_N];
const int INF = 3 * MAX_N;
inline void solve() {
    int N;
    scanf("%d", &N);
    string A, B;
    cin >> A >> B;
    A = "1" + A + "1";
    B = "2" + B + "2";
    FOR(i, N + 2) FOR(j, 27) {
        dp1[j][i] = dp2[j][i] = INF;
    }
    FOR(i, 27) dp1[i][0] = 0;
    FOR(i, 27) dp2[i][N + 1] = 0;
    for (int j = 1; j <= N; ++j) FOR(i, 27) {
        if (i == 0) {
            if (A[j] == B[j]) dp1[i][j] = dp1[i][j - 1];
            else dp1[i][j] = 1 + dp1[B[j] - 'A' + 1][j - 1];
        }
        else {
            if (B[j] - 'A' + 1 == i) dp1[i][j] = dp1[i][j - 1];
            else dp1[i][j] = 1 + dp1[B[j] - 'A' + 1][j - 1];
        }
    }
    for (int j = N; j >= 1; --j) FOR(i, 27) {
        if (i == 0) {
            if (A[j] == B[j]) dp2[i][j] = dp2[i][j + 1];
            else dp2[i][j] = 1 + dp2[B[j] - 'A' + 1][j + 1];
        }
        else {
            if (B[j] - 'A' + 1 == i) dp2[i][j] = dp2[i][j + 1];
            else dp2[i][j] = 1 + dp2[B[j] - 'A' + 1][j + 1];
        }
    }
    int res = INF;
    FOR(i, N + 1) {
        res = min(res, max(dp1[0][i], dp2[0][i + 1]));
    }
    cout << res << endl;
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
