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

int n, m, s;
vector<vector<int> > g;
vector<vector<pair<int, int> > > ng;
vector<int> scc, cnt, dis;
int ptr, seq;
// vector<bool> visited;
stack<int> st;
vector<int> low, label;

void tarjan_scc(int v) {
    assert(scc[v] == -1 && low[v] == -1 && label[v] == -1);
    // visited[v] = true;
    low[v] = label[v] = seq++;
    st.push(v);
    FOR(i, g[v].size()) {
        int to = g[v][i];
        if (scc[to] != -1) continue;
        if (low[to] == -1) tarjan_scc(to);
        low[v] = min(low[v], low[to]);
        // st.push(to);
    }
    if (low[v] == label[v]) {
        while (st.top() != v) {
            assert(scc[st.top()] == -1);
            scc[st.top()] = ptr;
            st.pop();
            assert(!st.empty());
            cnt[ptr]++;
        }
        cnt[ptr]++; st.pop(); scc[v] = ptr++;
    }
    return;
}

void spfa(int src) {
    queue<int> q;
    q.push(src);
    vector<bool> inq(ptr, false);
    inq[src] = true;
    while (!q.empty()) {
        int tp = q.front(); q.pop(); inq[tp] = false;
        FOR(i, ng[tp].size()) {
            pair<int, int>& edge = ng[tp][i];
            if (dis[tp] + edge.second > dis[edge.first]) {
                if (!inq[edge.first]) {
                    q.push(edge.first);
                    inq[edge.first] = true;
                }
                dis[edge.first] = dis[tp] + edge.second;
            }
        }
    }
    return;
}

int main() {
    int from, to, tcase = 0;
    while (scanf("%d %d %d", &n, &m, &s) != EOF) {
        g.resize(n); --s; ++tcase;
        FOR(i, n) g[i].clear();
        FOR(i, m) {            
            scanf("%d %d", &from, &to);
            --from; --to;
            g[from].push_back(to);
        }
        scc.resize(n); cnt.resize(n);
        fill(scc.begin(), scc.end(), -1);
        fill(cnt.begin(), cnt.end(), 0);        
        ptr = seq = 0;
        // visited.resize(n);
        // fill(visited.begin(), visited.end(), false);
        while (!st.empty()) st.pop();
        low.resize(n); label.resize(n);
        fill(low.begin(), low.end(), -1);
        fill(label.begin(), label.end(), -1);   
        FOR(i, n) {
            if (scc[i] == -1) tarjan_scc(i);
        }
        // FOR(i, n) {
        //     printf("%d: %d\n", i + 1, scc[i]);
        // }
        ng.resize(ptr);
        FOR(i, ptr) ng[i].clear();
        FOR(i, n) {
            from = scc[i];
            FOR(j, g[i].size()) {
                to = scc[g[i][j]];
                if (from != to) ng[from].push_back(make_pair(to, cnt[to]));
            }
        }
        dis.resize(ptr);
        fill(dis.begin(), dis.end(), 0);
        spfa(scc[s]);
        int res = *max_element(dis.begin(), dis.end()) + cnt[scc[s]];
        printf("Case %d:\n", tcase);
        printf("%d\n", res);
    }
    return 0;
}
