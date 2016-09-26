#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dp[11][18][18], nt[11][18][18];
int n, a, b, val[18];
int INF = 12345;
int f(int pos, int p2, int p1) {
    if (pos == n) {
        if (p1 == 0 && p2 * b > val[n]) return 0;
        else return INF;
    }
    if (dp[pos][p2][p1] >= 0) {
        return dp[pos][p2][p1];
    }
    dp[pos][p2][p1] = INF;
    for (int i = 0; i <= 16; ++i) {
        if (p2 * b + p1 * a + i * b <= val[pos]) {
            continue;
        } else {
            int cur = f(pos + 1, p1, i) + i;
            if (cur < dp[pos][p2][p1]) {
                dp[pos][p2][p1] = cur;
                nt[pos][p2][p1] = i;
            }
        }
    }
    return dp[pos][p2][p1];
}
void output(int pos, int p2, int p1) {
    if (pos == n) return;
    FOR(i, p1) cout << pos << " ";
    output(pos + 1, p1, nt[pos][p2][p1]);
}
int main() {
    while (cin >> n >> a >> b) {
        memset(dp, -1, sizeof dp);
        for (int i = 1; i <= n; ++i) {
            cin >> val[i];
        }
        int res = INF;
        for (int i = 0; i <= 16; ++i) {
            if (i * b <= val[1]) {
                continue;
            }
            res = min(res, f(2, 0, i) + i);
        }
        cout << res << endl;
        for (int i = 16; i >= 0; --i) {
            if (f(2, 0, i) + i == res) {
                output(2, 0, i);
                break;
            }
        }
        cout << endl;
    }
    return 0;
}
