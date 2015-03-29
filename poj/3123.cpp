// Minimal Steiner Tree problem
#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
#include <algorithm>
#include <string>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int INF = INT_MAX / 4;
int main() {
    vector<vector<int> > g(31, vector<int>(31));
    int dp[256][31], n, m;
    map<string, int> mp;
    string city, from, to;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        mp.clear();
        FOR(i, n) {
            cin >> city;
            mp[city] = i;
        }        
        FOR(i, n) fill(g[i].begin(), g[i].end(), INF);
        FOR(i, n) g[i][i] = 0;
        int dis;
        FOR(i, m) {
            cin >> from >> to >> dis;
            int u = mp[from], v = mp[to];
            // undirected graph
            g[u][v] = min(g[u][v], dis);
            g[v][u] = min(g[v][u], dis);
        }
        vector<int> target(8);
        FOR(i, 8) {
            cin >> city;
            target[i] = mp[city];
        }

        // floyd algorithm to compute all pair shortest path
        FOR(k, n) FOR(i, n) FOR(j, n) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

        FOR(i, 256) FOR(j, 31) dp[i][j] = INF;
        FOR(i, 8) FOR(j, n) dp[1 << i][j] = g[target[i]][j];
        FOR(j, n) dp[0][j] = 0;

        FOR(i, 256) {
            if ((i & (i - 1)) == 0) continue; // only one bit
            // dynamic programming, first case
            FOR(j, n) {
                // calculate dp[i][j]
                FOR(k, 256) {
                    if ((k | i) == i) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
                }
            }
            // dynamic programming, second case
            vector<bool> visited(n, false);
            FOR(j, n) {
                int mn = INF, idx = -1;
                FOR(k, n) {
                    if (dp[i][k] < mn && !visited[k]) { mn = dp[i][k]; idx = k; }
                }
                // assert(idx != -1);
                visited[idx] = true;
                FOR(k, n) dp[i][idx] = min(dp[i][idx], dp[i][k] + g[idx][k]);
            }
        }

        // enumerate all possible combinations
        int res = INF;
        // there are some duplicate cases, but never mind.... it will still run blazingly fast.
        FOR(i, 256) {
            vector<int> tag(4, 0);
            for (int j = 0; j < 8; j += 2) {
                int t = (i >> j) & 3;
                tag[t] |= (1 << j);
                tag[t] |= (1 << (j + 1));
            }
            int val = 0;
            FOR(j, 4) {
                if (!tag[j]) continue;
                int mn = INF;
                FOR(k, 256) FOR(rt, n) {
                    mn = min(mn, dp[tag[j] | k][rt]);
                }
                val += mn;
            }
            res = min(res, val);
        }
        cout << res << endl;
    }
    return 0;
}
