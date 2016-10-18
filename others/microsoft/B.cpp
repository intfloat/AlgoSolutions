#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = INT_MAX / 2;
char s[100005];
bool banned[1000];
inline bool check(int a, int b) {
    return !banned[a * 26 + b];
}
int main() {
    int n, m;
    scanf("%d", &n);
    memset(banned, false, sizeof banned);
    scanf("%s", s);
    scanf("%d", &m);
    char cc[5];
    FOR(i, m) {
        scanf("%s", cc);
        int a = cc[0] - 'a';
        int b = cc[1] - 'a';
        banned[a * 26 + b] = true;
        banned[b * 26 + a] = true;
    }
    vector<vector<int> > dp(n, vector<int>(27, INF));
    FOR(i, n) dp[i][26] = i + 1;
    dp[0][s[0] - 'a'] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            int cur = s[i] - 'a';
            if (cur != j) dp[i][j] = min(INF, dp[i - 1][j] + 1);
            else {
                dp[i][j] = min(dp[i - 1][26], dp[i - 1][j] + 1);
                for (int k = 0; k < 26; ++k) {
                    if (!check(k, j)) continue;
                    dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                }
            }
        }
    }
    int res = INF;
    FOR(i, 27) res = min(res, dp[n - 1][i]);
    cout << res << endl;
    return 0;
}
