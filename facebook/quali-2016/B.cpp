#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
const int INF = INT_MAX / 4;
string g[2];
int dp[1005 * 32];
int calc(int pos, bool r1, bool r2, bool c1, bool c2) {
    int num = pos * 16 + r1 * 8 + r2 * 4 + c1 * 2 + c2;
    if (dp[num] >= 0) return dp[num];
    int res = INF;
    if (pos == N) {
        if (!r1 && !r2) res = 0;
        else res = INF;
    }
    else if (g[0][pos] == 'X' && g[1][pos] == 'X') {
        if (r1 || r2) res = INF;
        else res = calc(pos + 1, false, false, false, false);
    }
    else if (g[0][pos] == 'X') {
        if (r1) res = INF;
        else if (c2) {
            res = calc(pos + 1, false, false, false, true);
        }
        else {
            int res1 = calc(pos + 1, false, true, false, false);
            int res2 = 1 + calc(pos + 1, false, false, false, true);
            res = min(res1, res2);
        }
    }
    else if (g[1][pos] == 'X') {
        if (r2) res = INF;
        else if (c1) {
            res = calc(pos + 1, false, false, true, false);
        }
        else {
            int res1 = calc(pos + 1, true, false, false, false);
            int res2 = 1 + calc(pos + 1, false, false, true, false);
            res = min(res1, res2);
        }
    }
    else {
        int res1 = calc(pos + 1, !c1, !c2, c1, c2);
        int res2 = 1 + calc(pos + 1, false, !c2 && r2, true, c2);
        int res3 = 1 + calc(pos + 1, !c1 && r1, false, c1, true);
        int res4 = 2 + calc(pos + 1, false, false, true, true);
        res = min(min(res1, res2), min(res3, res4));
    }
    dp[num] = res;
    return dp[num];
}
inline void solve() {
    cin >> N;
    cin >> g[0] >> g[1];
    assert(N == (int)g[0].size());
    memset(dp, -1, sizeof dp);
    cout << calc(0, 0, 0, 0, 0) << endl;
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
