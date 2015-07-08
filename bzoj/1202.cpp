#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<int> > g;
vector<vector<bool> > ok;
int n;
inline void update(int from, int to) {
    if (from != to && ok[from][from] && !ok[from + 1][to]) {
        ok[from + 1][to] = true;
        g[from + 1][to] = g[from][to] - g[from][from];
    }
    if (from != to && ok[to][to] && !ok[from][to - 1]) {
        ok[from][to - 1] = true;
        g[from][to - 1] = g[from][to] - g[to][to];
    }
    for (int i = from; i < n; ++i) {
        if (i < to && ok[from][i] && !ok[i + 1][to]) {
            ok[i + 1][to] = true;
            g[i + 1][to] = g[from][to] - g[from][i];
        }
        if (i > to && ok[from][i] && !ok[to + 1][i]) {
            ok[to + 1][i] = true;
            g[to + 1][i] = g[from][i] - g[from][to];
        }
        if (i > to && !ok[from][i] && ok[to + 1][i]) {
            ok[from][i] = true;
            g[from][i] = g[from][to] + g[to + 1][i];
        }
    }
    for (int i = 0; i <= to; ++i) {
        if (i < from && ok[i][from - 1] && !ok[i][to]) {
            ok[i][to] = true;
            g[i][to] = g[i][from - 1] + g[from][to];
        }
        if (from < i && !ok[from][i - 1] && ok[i][to]) {
            ok[from][i - 1] = true;
            g[from][i - 1] = g[from][to] - g[i][to];
        }
        if (i < from && ok[i][to] && !ok[i][from - 1]) {
            ok[i][from - 1] = true;
            g[i][from - 1] = g[i][to] - g[from][to];
        }
    }
    return;
}
inline void solve() {
    bool sol = false;
    int m, from, to, money;
    scanf("%d %d", &n, &m);
    g.resize(n);
    ok.resize(n);
    for (int i = 0; i < g.size(); ++i) {
        g[i].resize(n);
        ok[i].resize(n);
        fill(ok[i].begin(), ok[i].end(), false);
    }
    string res = "true";
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &from, &to, &money);
        if (sol) { // already get solution, need to consume remaining input
            continue;
        }
        --from; --to;
        if (ok[from][to] && g[from][to] != money) {
            res = "false";
            sol = true;
        }
        else if (!ok[from][to]) {
            ok[from][to] = true;
            g[from][to] = money;
            update(from, to);
        }
    }
    printf("%s\n", res.c_str());
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
