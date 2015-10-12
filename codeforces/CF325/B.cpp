#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<string> g(3);
bool dp[350][3];
inline void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    char s[105];
    FOR(i, 3) {
        scanf("%s", s);
        g[i] = s;
    }
    memset(dp, false, sizeof dp);
    FOR(i, 3) {
        dp[0][i] = (g[i][0] == 's');
        if (g[i][0] == 's') g[i][0] = '.';
        while (g[i].size() < 350) g[i].push_back('.');
    }
    for (int i = 1; i <= n - 1; ++i) {
        bool ok[3];
        memset(ok, true, sizeof ok);
        FOR(j, 3) for (int p = i * 3 - 2; p <= i * 3; ++p) ok[j] = ok[j] && (g[j][p] == '.');
        bool a = dp[i * 3 - 3][0] && (g[0][i * 3 - 2] == '.');
        bool b = dp[i * 3 - 3][1] && (g[1][i * 3 - 2] == '.');
        bool c = dp[i * 3 - 3][2] && (g[2][i * 3 - 2] == '.');
        dp[i * 3][0] = ok[0] && (dp[i * 3 - 3][0] || b);
        dp[i * 3][1] = ok[1] && (a || dp[i * 3 - 3][1] || c);
        dp[i * 3][2] = ok[2] && (b || dp[i * 3 - 3][2]);
    }
    int pos = (n - 1) * 3;
    if (dp[pos][0] || dp[pos][1] || dp[pos][2]) printf("YES\n");
    else printf("NO\n");
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
