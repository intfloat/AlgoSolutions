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
typedef long long ll;

vector<ll> cnt;
vector<int> parent;
vector<bool> visited;
vector<vector<int> > g;
void solve() {
    int n, s, u, p, to, v;
    scanf("%d %d", &n, &s);
    --s; cnt.resize(n);
    g.resize(n);
    FOR(i, g.size()) g[i].clear();
    FOR(i, n - 1) {
        scanf("%d %d", &u, &v);
        --u; --v;
        g[u].push_back(v); g[v].push_back(u);
    }
    FOR(i, n) scanf("%lld", &cnt[i]);
    visited.resize(n); parent.resize(n);
    fill(visited.begin(), visited.end(), false);
    queue<int> q; q.push(s); visited[s] = true;
    parent[s] = -1;
    vector<int> arr;
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        arr.push_back(tp);
        FOR(i, g[tp].size()) {
            to = g[tp][i];
            if (visited[to]) continue;
            visited[to] = true;
            q.push(to);
            parent[to] = tp;
        }
    }
    vector<vector<pair<ll, ll> > > res(n);
    reverse(arr.begin(), arr.end());
    FOR(i, arr.size()) {
        u = arr[i];        
        if (u == s) break;
        FOR(j, res[u].size()) { ++res[u][j].first; ++res[u][j].second; }
        if (cnt[u] > 0) res[u].push_back(make_pair(0, cnt[u] - 1));
        sort(res[u].begin(), res[u].end());
        if (res[u].size() == 0) continue;
        p = parent[u];
        int ptr = 0;
        for (int j = 1; j < res[u].size(); ++j) {
            if (res[u][j].first <= res[u][ptr].second + 1)
                res[u][ptr].second += res[u][j].second - res[u][j].first + 1;
            else {
                ++ptr;
                res[u][ptr] = res[u][j];
            }
        }
        res[u].resize(ptr + 1);
        FOR(j, res[u].size()) res[p].push_back(res[u][j]);
    }
    ll mx = -1;    
    FOR(i, res[s].size()) mx = max(mx, res[s][i].second);
    printf("%lld\n", mx + 1);
    return;
}

int main() {
    int TestCase;
    scanf("%d", &TestCase);
    FOR(caseID, TestCase) {
        printf("Case #%d: ", caseID + 1);        
        solve();
    }
    return 0;
}
