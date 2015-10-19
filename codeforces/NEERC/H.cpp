#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 50005;
const int MAX_M = MAX_N * 2;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], ptr = 0;
bool marked[MAX_N], visited[MAX_N];
inline void addedge(int x, int y) {
    pnt[ptr] = y; nt[ptr] = head[x]; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; head[y] = ptr++;
}
vector<vector<int> > res;
vector<int> dfs(int pos) {
    visited[pos] = true;
    vector<int> pv;
    for (int i = head[pos]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (visited[to]) continue;
        vector<int> qv = dfs(to);
        if (qv.empty()) continue;
        else if (pv.empty()) pv = qv;
        else {
            pv.push_back(pos);
            reverse(qv.begin(), qv.end());
            FOR(j, qv.size()) pv.push_back(qv[j]);
            res.push_back(pv);
            pv.clear();
        }
    }
    if (marked[pos] && !pv.empty()) {
        pv.push_back(pos);
        res.push_back(pv);
        pv.clear();
    }
    else if (marked[pos] && pv.empty()) pv.push_back(pos);
    else if (!marked[pos] && !pv.empty()) pv.push_back(pos);
    else pv.clear();
    return pv;
}
int main() {
    int n, m, k, x, y;
    scanf("%d %d %d", &n, &m, &k);
    memset(head, -1, sizeof head);
    memset(marked, false, sizeof marked);
    memset(visited, false, sizeof visited);
    FOR(i, m) {
        scanf("%d %d", &x, &y);
        addedge(x, y);
    }
    FOR(i, k) {
        scanf("%d", &x);
        marked[x] = true;
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    printf("%d\n", (int)res.size());
    FOR(i, res.size()) {
        printf("%d", (int)res[i].size() - 1);
        FOR(j, res[i].size()) printf(" %d", res[i][j]);
        printf("\n");
    }
    return 0;
}
