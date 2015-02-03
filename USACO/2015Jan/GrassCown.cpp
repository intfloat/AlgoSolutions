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
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MAX_N = 100005;
int N, M;
vector<vector<int> > g, sccg, sccrg;
vector<int> scc, low, dfn, wei;
int scc_cnt, df_cnt;
stack<int> st;

void tarjan_scc(int idx) {
    low[idx] = dfn[idx] = df_cnt++;    
    st.push(idx);
    for (int i = 0; i < g[idx].size(); ++i) {
        int to = g[idx][i];
        if (dfn[to] < 0) {
            tarjan_scc(to);
            low[idx] = min(low[idx], low[to]);
        }
        else low[idx] = min(low[idx], low[to]);
    }
    // this is the root of Connected Component
    int total = 0;
    if (low[idx] == dfn[idx]) {
        while (st.top() != idx) {
            scc[st.top()] = scc_cnt;            
            dfn[st.top()] = low[st.top()] = MAX_N;
            st.pop(); ++total;
        }        
        scc[idx] = scc_cnt++;
        dfn[idx] = low[idx] = MAX_N;
        ++total; st.pop();
        // represent the weight of this connected component
        wei.push_back(total);
        assert(wei.size() == scc_cnt);
    }    
    return;
}

void construct_graph() {
    sccg.resize(scc_cnt);
    FOR(i, g.size()) FOR(j, g[i].size()) {
        int from = scc[i], to = scc[g[i][j]];
        if (from == to) continue;
        sccg[from].push_back(to);
    }
    FOR(i, sccg.size()) {
        sort(sccg[i].begin(), sccg[i].end());
        int len = unique(sccg[i].begin(), sccg[i].end()) - sccg[i].begin();
        sccg[i].resize(len);
    }
    // construct reverse graph
    sccrg.resize(sccg.size());
    FOR(i, sccg.size()) FOR(j, sccg[i].size()) {
        int from = sccg[i][j], to = i;
        sccrg[from].push_back(to);
    }
    return;
}

// compute longest path in a DAG
void spfa(const vector<vector<int> >& graph, vector<int>& res) {
    res.resize(graph.size());
    fill(res.begin(), res.end(), -1);
    vector<bool> inq(graph.size(), false);
    queue<int> q;
    // FOR(i, graph.size()) {
    //     cout << i << ": ";
    //     FOR(j, graph[i].size()) cout << graph[i][j] << " ";
    //     cout << endl;
    // }
    q.push(scc[0]); res[scc[0]] = wei[scc[0]]; inq[scc[0]] = true;
    while (!q.empty()) {
        int tp = q.front(); q.pop(); inq[tp] = false;
        FOR(i, graph[tp].size()) {
            int to = graph[tp][i];
            if (res[tp] + wei[to] > res[to]) {
                res[to] = res[tp] + wei[to];                
                if (!inq[to]) { q.push(to); inq[to] = true; }
            }
        }
    }
    return;
}

int main() {
    // freopen("grass.in", "r", stdin);
    // freopen("grass.out", "w", stdout);
    scanf("%d %d", &N, &M);
    g.resize(N);
    int from, to;
    FOR(i, M) {
        scanf("%d %d", &from, &to);
        --from; --to;
        g[from].push_back(to);
    }

    // compute Strongly Connected Component
    scc_cnt = df_cnt = 0; scc.resize(N); dfn.resize(N); low.resize(N);
    fill(scc.begin(), scc.end(), -1);
    fill(dfn.begin(), dfn.end(), -1);
    fill(low.begin(), low.end(), -1);
    for (int i = 0; i < g.size(); ++i) {
        if (dfn[i] < 0) {
            assert(scc[i] < 0);
            tarjan_scc(i);
        }
        assert(scc[i] >= 0);
    }

    // cout << "Number of SCC: " << scc_cnt << endl;

    // construct graph & reverse graph
    construct_graph();
    vector<int> val, rval;
    // cout << "Start to run spfa..." << endl;
    spfa(sccg, val);
    spfa(sccrg, rval);
    int res = wei[scc[0]];
    // FOR(i, wei.size()) {
    //     cout << "Number of vertices: " << i << ": " << wei[i] << endl;
    // }
    // try every edge
    FOR(i, sccg.size()) FOR(j, sccg[i].size()) {
        from = i, to = sccg[i][j];
        if (val[to] >= 0 && rval[from] >= 0) {
            res = max(res, val[to] + rval[from] - wei[scc[0]]);
        }
    }
    printf("%d\n", res);
    return 0;
}
