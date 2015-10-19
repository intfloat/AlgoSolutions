#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int g[20][20], total, prob[20][20];
vector<int> perm;
bool ok, visited[20];
void dfs(int pos) {
    if (ok || pos == total) {
        ok = true;
        return;
    }
    for (int i = 1; i < total; ++i) {
        if (visited[i] || prob[pos][i] > 0) continue;
        if (i % 2 && !visited[i - 1]) continue;
        visited[i] = true;
        perm[pos] = i;
        for (int j = pos + 1; j < total; ++j) {
            if (g[pos][j] > 0) {
                int cur = i - i % (1 << g[pos][j]);
                FOR(k, 1 << g[pos][j]) ++prob[j][k + cur];
            }
        }
        dfs(pos + 1);
        if (ok) return;
        for (int j = pos + 1; j < total; ++j) {
            if (g[pos][j] > 0) {
                int cur = i - i % (1 << g[pos][j]);
                FOR(k, 1 << g[pos][j]) --prob[j][k + cur];
            }
        }
        visited[i] = false;
    }
}
void solve() {
    int N, M, E, K, B, X;
    cin >> N >> M;
    memset(g, 0, sizeof g);
    int mx = 0;
    FOR(i, M) {
        cin >> E >> K >> B;
        mx += (K >= N);
        --E;
        FOR(j, B) {
            cin >> X; --X;
            g[E][X] = max(K, g[E][X]);
            g[X][E] = max(K, g[X][E]);
        }
    }
    if (mx > 0) { printf("NO\n"); return; }
    total = (1 << N);
    perm.resize(total);
    memset(visited, false, sizeof visited);
    memset(prob, 0, sizeof prob);
    perm[0] = 0; visited[0] = true;
    FOR(i, total) {
        if (g[0][i] > 0) {
            for (int j = 0; j < (1 << g[0][i]); ++j) {
                ++prob[i][j];
            }
        }
    }
    ok = false; dfs(1);
    if (ok) printf("YES\n");
    else printf("NO\n");
    return;
}
int main() {
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ": ";
        solve();
    }
    return 0;
}
