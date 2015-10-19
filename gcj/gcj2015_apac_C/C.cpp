#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
int g[20][20], total;
bool visited[20];
int dp[1 << 16];
vector<int> arr[16];
int dfs(int status, int cnt) {
    if (dp[status] >= 0) return dp[status];
    if (cnt == 0) {
    	dp[status] = 1;
    	return dp[status];
    }
    FOR(i, total) {
    	if (((1 << i) & status) == 0) continue;
    	for (int j = i + 1; j < total; ++j) {
    		if (g[i][j] >= cnt) {
    			int a = ((1 << j) & status);
    			if (a > 0) { dp[status] = 0; return dp[status]; }
    		}
    	}
    }
    int index = (1 << (cnt - 1));
    FOR(i, arr[index].size()) {
    	int a = arr[index][i];
    	int b = status - a;
    	if ((status & a) == a && a < b) {
    		dp[status] = dfs(a, cnt - 1) && dfs(b, cnt - 1);
    	}
    	if (dp[status] > 0) return dp[status];
    }
    return dp[status];
}
void solve() {
    int N, M, E, K, B, X;
    cin >> N >> M;
    memset(g, 0, sizeof g);
    FOR(i, M) {
        cin >> E >> K >> B;
        --E;
        FOR(j, B) {
            cin >> X; --X;
            g[E][X] = max(K, g[E][X]);
            g[X][E] = max(K, g[X][E]);
        }
    }
    total = (1 << N);
    FOR(i, 1 << total) dp[i] = -1;
    if (dfs((1 << total) - 1, N)) printf("YES\n");
    else printf("NO\n");
}
int main() {
	FOR(i, 1 << 16) {
		arr[__builtin_popcount(i)].push_back(i);
	}
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ": ";
        solve();
    }
    return 0;
}
