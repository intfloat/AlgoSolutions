#include <stdio.h>
#include <vector>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;

const int MAX_N = 1005;
const int ROOT = 1;
vector<vector<int> > g(MAX_N);
vector<int> cnt(MAX_N), low(MAX_N), dfn(MAX_N);
int seq = 1;
void tarjan(int pos, int fa) {
    if (dfn[pos] >= 0) return;
    dfn[pos] = seq++;
    low[pos] = dfn[pos];
    FOR(i, g[pos].size()) {
        int to = g[pos][i];
        if (to == fa) continue;
        if (dfn[to] >= 0) {
            low[pos] = min(low[pos], dfn[to]);
        } else {
            tarjan(to, pos);
            if (low[to] >= dfn[pos]) {
                ++cnt[pos];
            }
            low[pos] = min(low[pos], low[to]);
        }
    }
}
int main() {
    int u, v, num = 1;
    while (true) {
        scanf("%d", &u);
        if (u == 0) break;
        scanf("%d", &v);
        FOR(i, MAX_N) g[i].clear();
        g[u].push_back(v);
        g[v].push_back(u);
        while (true) {
            scanf("%d", &u);
            if (u == 0) break;
            scanf("%d", &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        printf("Network #%d\n", num++);
        fill(cnt.begin(), cnt.end(), 0);
        fill(low.begin(), low.end(), -1);
        fill(dfn.begin(), dfn.end(), -1);
        seq = 1;
        tarjan(ROOT, -1);
        bool has_cut = false;
        for (int i = 1; i < MAX_N; ++i) {
            if (i == ROOT && cnt[i] > 1) {
                has_cut = true;
                printf("  SPF node %d leaves %d subnets\n", i, cnt[i]);
            }
            else if (i != ROOT && cnt[i] > 0) {
                has_cut = true;
                printf("  SPF node %d leaves %d subnets\n", i, cnt[i] + 1);
            }
        }
        if (!has_cut) {
            printf("  No SPF nodes\n");
        }
        printf("\n");
    }
    return 0;
}
