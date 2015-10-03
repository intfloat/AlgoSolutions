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
#include <tuple>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

void solve(const vector<vector<tuple<int, int> > >& graph, 
            vector<vector<bool> >& dp) {

    int MAX_TM = dp[0].size();
    queue<tuple<int, int> > q;    
    q.push(make_tuple(1, 0)); dp[1][0] = true;
    // Run spfa algorithm to do dynamic programming on directed graph
    while (!q.empty()) {
        tuple<int, int> tp = q.front(); q.pop();
        int from = get<0>(tp), len = get<1>(tp);
        FOR(i, graph[from].size()) {
            int to = get<0>(graph[from][i]);
            int w = get<1>(graph[from][i]);
            if (len + w >= MAX_TM) continue;
            if (dp[to][len + w] == false) {
                dp[to][len + w] = true;
                q.push(make_tuple(to, len + w));                
            }
            // tuple<int, int> nstate = make_tuple(to, len + w);            
        }
    }
    return;
}

int main() {
    freopen("meeting.in", "r", stdin);
    freopen("meeting.out", "w", stdout);
    int N, M, from, to, w1, w2;
    scanf("%d %d", &N, &M);
    vector<vector<tuple<int, int> > > bessie, elsie;
    bessie.resize(N + 1); elsie.resize(N + 1);
    FOR(i, M) {
        scanf("%d %d %d %d", &from, &to, &w1, &w2);
        bessie[from].emplace_back(make_tuple(to, w1));
        elsie[from].emplace_back(make_tuple(to, w2));
    }
    vector<vector<bool> > dp1(N + 1, vector<bool>(100 * (N + 1), false));
    vector<vector<bool> > dp2(N + 1, vector<bool>(100 * (N + 1), false));
    solve(bessie, dp1);
    solve(elsie, dp2);
    FOR(i, dp1[0].size()) {
        if (dp1[N][i] && dp2[N][i]) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}
