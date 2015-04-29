#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int n;
vector<vector<int> > g;
vector<int> pre;
bool visited[505 * 2];

bool match(int idx) {
    if (visited[idx]) return false;
    visited[idx] = true;
    FOR(i, g[idx].size()) {
        int to = g[idx][i];
        if (visited[n + to]) continue;
        visited[n + to] = true;
        if (pre[to] == -1 || match(pre[to])) {
            pre[to] = idx;
            return true;
        }
    }
    return false;
}
int main() {
    int id, cnt, val;
    while (scanf("%d", &n) != EOF) {   
        g.resize(n); pre.resize(n);
        fill(pre.begin(), pre.end(), -1);
        FOR(i, n) g[i].clear();
        FOR(i, n) {
            char c1, c2, c3;
            scanf("%d %c %c %d %c", &id, &c1, &c2, &cnt, &c3);
            FOR(j, cnt) {
                scanf("%d", &val);
                g[id].push_back(val);
            }
        }
        int res = 0;
        FOR(i, n) {
            memset(visited, false, sizeof visited);
            res += match(i);
        }
        // assert(res % 2 == 0);
        printf("%d\n", n - res / 2);
    }
    return 0;
}
