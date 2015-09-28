#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 3005;
const int MAX_M = MAX_N * 2;
const int INF = INT_MAX / 2;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], from[MAX_M], cost[MAX_M], ptr = 0;
int mdis[MAX_M], root;
int g[MAX_N][MAX_N];
inline void addedge(int x, int y, int w) {
    pnt[ptr] = y; from[ptr] = x; nt[ptr] = head[x]; cost[ptr] = w; head[x] = ptr++;
    pnt[ptr] = x; from[ptr] = y; nt[ptr] = head[y]; cost[ptr] = w; head[y] = ptr++;
}
set<pii> st;
int dfs(int pos, int fa) {
    int cur = INF;
    for (int i = head[pos]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to == fa) continue;
        int ret = dfs(to, pos);
        mdis[i] = min(mdis[i], ret);
        cur = min(cur, ret);
    }
    if (st.find(make_pair(root, pos)) == st.end()) {
        cur = min(cur, g[root][pos]);
    }
    return cur;
}
inline void solve() {
    memset(head, -1, sizeof head);
    ptr = 0; st.clear();
    int n, w;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) g[i][i] = 0;
    FOR(i, n - 1) FOR(j, n - i - 1) {
        scanf("%d", &w);
        g[i + 1][i + j + 2] = g[i + j + 2][i + 1] = w;
    }
    // prim algorithm to get minimum spanning tree
    vector<int> dis(n + 1, INF);
    vector<int> pv(n + 1, -1);
    vector<bool> visited(n + 1, false);
    dis[1] = 0; visited[1] = true;
    for (int i = 2; i <= n; ++i) dis[i] = g[1][i], pv[i] = 1;
    FOR(j, n - 1) {
        int mn = INF, pos = -1;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && dis[i] < mn) {
                mn = dis[i];
                pos = i;
            }
        }
        visited[pos] = true;
        addedge(pv[pos], pos, g[pos][pv[pos]]);
        st.insert(make_pair(pv[pos], pos));
        st.insert(make_pair(pos, pv[pos]));
        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && dis[i] > g[pos][i]) {
                dis[i] = g[pos][i];
                pv[i] = pos;
            }
        }
    }
    FOR(i, ptr) mdis[i] = INF;
    for (int i = 1; i <= n; ++i) {
        root = i; dfs(i, -1);
    }
    int res = n - 1;
    FOR(i, n - 1) {
        if (mdis[2 * i] == cost[2 * i] || mdis[2 * i + 1] == cost[2 * i + 1]) {
            --res;
        }
    }
    printf("%d\n", res);
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
