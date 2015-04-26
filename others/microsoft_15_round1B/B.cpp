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
const int MAX_N = 2000005;
int head[MAX_N], pnt[MAX_N], nt[MAX_N], ptr = 0;
void addedge(int from, int to) {
    pnt[ptr] = to; nt[ptr] = head[from]; head[from] = ptr++;
    pnt[ptr] = from; nt[ptr] = head[to]; head[to] = ptr++;
}

int mn, idx;
vector<bool> visited;
vector<ll> w;
void bfs(int pos) {
    if (w[pos] < mn) {
        mn = w[pos]; idx = pos;
    }
    visited[pos] = true;
    for (int i = head[pos]; i != -1; i = nt[i]) {
        int v = pnt[i];
        if (visited[v]) continue;
        bfs(v);
    }
}

void solve() {
    int m, n, k, u, v;
    ptr = 0;
    memset(head, -1, sizeof(head));
    scanf("%d %d %d", &n, &m, &k);
    w.resize(n);
    FOR(i, n) scanf("%lld", &w[i]);
    FOR(i, m) {
        scanf("%d %d", &u, &v);
        --u; --v;
        addedge(u, v);
    }
    visited.resize(n);
    fill(visited.begin(), visited.end(), false);
    vector<bool> chosen(n, false);
    int cc = 0;
    ll res = 0;
    FOR(i, n) {
        if (!visited[i]) {
            ++cc; mn = INT_MAX; idx = -1;
            bfs(i);
            // assert(idx != -1);
            chosen[idx] = true;
            res += w[idx];
        }
    }
    // assert(m >= n - cc);
    int t = m - (n - cc);
    if (t >= k) {
        cout << res << endl;
    }
    else {
        vector<ll> v1;
        k -= t;
        FOR(i, n) {
            if (!chosen[i]) v1.push_back(w[i]);            
        }
        sort(v1.begin(), v1.end());
        res += accumulate(v1.begin(), v1.begin() + k, 0ll);
        cout << res << endl;
    }
    return;
}

int main() {
    int T;
    cin >> T;
    FOR(tt, T) {
        cout << "Case #" << tt + 1 << ": ";
        solve();
    }    
    return 0;
}
