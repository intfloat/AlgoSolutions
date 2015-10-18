#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int g[20][20], total;
vector<int> perm;
int cnt = 0;
bool ok, visited[20];
void dfs(int pos) {
    if (ok || pos == total) {
        ok = true;
        return;
    }
    if (cnt > 200000000) return;
    ++cnt;
    for (int i = 1; i < total; ++i) {
        if (visited[i]) continue;
        if (i % 2 && !visited[i - 1]) continue;
        bool cc = true;
        FOR(j, pos) {
            if (g[pos][j] <= 0) continue;
            int t = ~((1 << g[pos][j]) - 1);
            int a = t & i;
            int b = t & perm[j];
            if (a == b) {
                cc = false;
                break;
            }
        }
        if (cc) {
            visited[i] = true;
            perm[pos] = i;
            dfs(pos + 1);
            if (ok) return;
            visited[i] = false;
        }
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
    perm[0] = 0; visited[0] = true;
    cnt = 0; ok = false; dfs(1);
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
