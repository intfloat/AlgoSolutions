#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1000005;
const ll MOD = 1000000007;
vector<vector<ll> > dp(2, vector<ll>(MAX_N));
vector<vector<int> > cnt(8, vector<int>(MAX_N, 0));
vector<int> sg(MAX_N);
void preprocess() {
    FOR(i, 10) sg[i] = 0;
    for (int i = 1; i < 10; ++i) cnt[0][i] = i;
    bool visited[8];
    for (int i = 10; i < MAX_N; ++i) {
        memset(visited, false, sizeof visited);
        int low = 1, up = 10;
        while (i >= up) {
            int x = (i / low) % 10;
            int y = (i / up) % 10;
            int r = (x + y) % 10;
            int num = i % low + r * low + (i / (up * 10)) * up;
            visited[sg[num]] = true;
            low *= 10;
            up *= 10;
        }
        FOR(j, 8) cnt[j][i] = cnt[j][i - 1];
        FOR(j, 8) {
            if (!visited[j]) {
                sg[i] = j;
                ++cnt[j][i];
                break;
            }
        }
    }
    dp[0][0] = 1, dp[1][0] = 0;
    for (int i = 1; i < MAX_N; ++i) {
        dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
        dp[1][i] = (dp[1][i - 1] + dp[0][i - 1]) % MOD;
    }
}
int tot[8], val;
bool odd[8];
ll res;
void dfs(int pos, int v) {
    if (pos == 8) {
        if (v != val) return;
        ll cur = 1ll;
        FOR(i, 8) {
            if (odd[i]) cur = (cur * dp[1][tot[i]]) % MOD;
            else cur = (cur * dp[0][tot[i]]) % MOD;
        }
        res = (res + cur) % MOD;
        return;
    }
    odd[pos] = false; dfs(pos + 1, v);
    odd[pos] = true; dfs(pos + 1, v ^ pos);
}
inline void solve() {
    int n, m, x;
    val = 0;
    scanf("%d %d", &n, &m);
    FOR(i, 8) tot[i] = cnt[i][n];
    FOR(i, m) {
        scanf("%d", &x);
        --tot[sg[x]];
        val ^= sg[x];
    }
    res = 0;
    dfs(0, 0);
    if (val == 0) res = (res - 1 + MOD) % MOD;
    printf("%lld\n", res);
}
int main() {
    preprocess();
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
