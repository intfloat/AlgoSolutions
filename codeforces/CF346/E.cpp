#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<vector<int> > g;
vector<int> res;
vector<bool> used;
int tot = 0;
void bfs(int s) {
    queue<int> q;
    q.push(s);
    used[s] = true;
    res.push_back(s);
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        FOR(i, g[tp].size()) {
            int to = g[tp][i];
            if (!used[to]) {
                res.push_back(to);
                q.push(to);
                used[to] = true;
            }
        }
    }
    int cnt = 0;
    FOR(i, res.size()) cnt += g[res[i]].size();
    cnt /= 2;
    tot += (cnt == ((int)res.size() - 1));
}
int main() {
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    g.resize(n);
    used.resize(n);
    fill(used.begin(), used.end(), false);
    FOR(i, m) {
        scanf("%d %d", &x, &y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    FOR(i, n) {
        if (!used[i]) {
            res.clear();
            bfs(i);
        }
    }
    printf("%d\n", tot);
    return 0;
}
