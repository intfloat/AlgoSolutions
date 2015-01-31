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

vector<vector<int> > g;
const int MAX_N = 200005;
pair<int, int> dp[MAX_N][2];

int main() {
    int T, N, p;
    cin >> T;
    FOR(tt, T) {
        cin >> N;
        g.resize(N + 1);
        FOR(i, g.size()) g[i].clear();
        FOR(i, N) {
            cin >> p;
            if (p != 0) g[p].push_back(i + 1);
        }
        FOR(i, N + 1) dp[i][0].first = dp[i][1].first = INT_MAX / 2;

        // get topological order
        bool visited[MAX_N];
        memset(visited, false, sizeof(visited));
        visited[1] = true;
        vector<int> q;
        q.push_back(1);
        FOR(i, q.size()) {
            int from = q[i];
            FOR(j, g[from].size()) {
                int to = g[from][j];
                // assert(visited[to] == false);
                visited[to] = true;
                q.push_back(to);
            }
        }
        reverse(q.begin(), q.end());

        // dynamic programming
        FOR(i, q.size()) {
            int v = q[i];
            if (g[v].empty()) {
                dp[v][0] = make_pair(1, 1);
                dp[v][1] = make_pair(2, 2);
            }
            else {
                pair<int, int> res;
                for (int cur = 1; cur < 20; ++cur) {
                    int mnval = 0;
                    FOR(j, g[v].size()) {
                        int to = g[v][j];
                        if (dp[to][0].second == cur) mnval += dp[to][1].first;
                        else mnval += dp[to][0].first;            
                    }
                    // assert(mnval < (INT_MAX / 2));
                    res = make_pair(mnval + cur, cur);
                    if (res < dp[v][0]) { dp[v][1] = dp[v][0]; dp[v][0] = res; }
                    else if (res < dp[v][1]) dp[v][1] = res;
                }
            }
        }
        // assert(dp[1][0].first < INT_MAX / 2);
        cout << "Case #" << tt + 1 << ": " << dp[1][0].first << endl;
    }
    return 0;
}
