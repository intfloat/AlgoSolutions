#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
char word[10];
vector<pair<int, string> > g[51];
string dist[51];
void solve() {
    int n, m, a, b, x, y;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    FOR(i, n) g[i].clear();
    FOR(i, m) {
        scanf("%d %d %s", &x, &y, word);
        string s(word);
        g[x].push_back(make_pair(y, s));
    }
    // run Bellman Ford algorithm
    vector<bool> ok(n, false);
    ok[b] = true; dist[b] = "";
    FOR(i, n * 6 + 1) {
        bool update = false;
        for (int j = 0; j < n; ++j) {
            FOR(k, g[j].size()) {
                int to = g[j][k].first;
                if (!ok[to]) continue;
                string cur = g[j][k].second;
                if (!ok[j] || dist[j] > cur + dist[to]) {
                    ok[j] = true;
                    update = true;
                    dist[j] = cur + dist[to];
                    if (i >= n - 1 && j == a) {
                        printf("Tough way!\n");
                        return;
                    }
                }
            }
        }
        if (!update) break;
    }
    if (!ok[a]) printf("Tough way!\n");
    else printf("%s\n", dist[a].c_str());
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        printf("Case #%d:\n", tt + 1);
        solve();
    }
    return 0;
}
