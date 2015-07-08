#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > g;
vector<int> match;
vector<bool> visited;
int n, m, x, y;
bool dfs(int pos) {
    if (visited[pos]) {
        return false;
    }
    visited[pos] = true;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (match[to] < 0 || dfs(match[to])) {
            match[to] = pos;
            match[pos] = to;
            return true;
        }
    }
    return false;
}
int main() {
    scanf("%d %d", &n, &m);
    g.resize(n + m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        g[i].push_back(x + m);
        if (y != x) {
            g[i].push_back(y + m);
        }
    }
    match.resize(m + n);
    visited.resize(m + n);
    fill(match.begin(), match.end(), -1);
    int res = -1;
    for (int i = 0; i < m; ++i) {
        if (match[i] < 0) {
            fill(visited.begin(), visited.end(), false);
            if (!dfs(i)) {
                res = i;
                break;
            }
        }
    }
    if (res < 0) {
        res = m;
    }
    printf("%d\n", res);
    return 0;
}
