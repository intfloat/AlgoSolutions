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
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

vector<vector<int> > g, queries;
vector<bool> visited;
vector<int> p, res;

int _find(int idx) {
    if (p[idx] == idx) return idx;
    p[idx] = _find(p[idx]);
    return p[idx];
}

void tarjan_lca(int idx) {
    visited[idx] = true;
    vector<int>& adj = queries[idx];
    FOR(i, adj.size()) {
        if (visited[adj[i]]) ++res[_find(adj[i])];
    }
    vector<int>& ch = g[idx];
    FOR(i, ch.size()) {
        if (!visited[ch[i]]) {
            tarjan_lca(ch[i]);
            p[ch[i]] = idx;
        }
    }
    return;
}

int main() {
    int N, x, y, deg, from, to, q;
    vector<bool> rt;
    while (scanf("%d", &N) != EOF) {
        g.resize(N + 1); rt.resize(N + 1); queries.resize(N + 1);
        visited.resize(N + 1); res.resize(N + 1); p.resize(N + 1);
        fill(res.begin(), res.end(), 0);
        FOR(i, p.size()) p[i] = i;
        fill(visited.begin(), visited.end(), false);
        fill(rt.begin(), rt.end(), true);
        FOR(i, g.size()) g[i].clear();
        FOR(i, queries.size()) queries[i].clear();
        FOR(i, N) {
            scanf("%d", &x);
            while (getchar() != '(');
            scanf("%d", &deg);
            while (getchar() != ')');            
            FOR(j, deg) {
                scanf("%d", &y);
                rt[y] = false;
                g[x].push_back(y);
            }            
        }
        scanf("%d", &q);
        FOR(i, q) {
            while (getchar() != '(');
            scanf("%d %d", &from, &to);
            queries[from].push_back(to); queries[to].push_back(from);
            while (getchar() != ')');
        }
        int idx = find(rt.begin() + 1, rt.end(), true) - rt.begin();
        // cout << "root: " << idx << endl;
        tarjan_lca(idx);
        FOR(i, res.size()) {
            if (res[i] == 0) continue;
            printf("%d:%d\n", i, static_cast<int>(res[i]));
        }
    }
    return 0;
}
