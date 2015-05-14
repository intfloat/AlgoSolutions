#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
int main() {
    freopen("buffet.in", "r", stdin);
    freopen("buffet.out", "w", stdout);
    int N, E, cnt, to;
    cin >> N >> E;
    vector<pair<int, int> > energy(N);
    vector<vector<int> > g(N, vector<int>());
    FOR(i, N) {
        cin >> energy[i].first;
        energy[i].second = i;
        cin >> cnt;
        FOR(j, cnt) {
            cin >> to; --to;
            g[i].push_back(to);
        }
    }
    sort(energy.begin(), energy.end());
    int res = 0;
    vector<int> dp(N);
    dp[0] = energy[0].first;
    vector<bool> visited(N);
    vector<int> dist(N);
    for (int i = 1; i < N; ++i) {
        dp[i] = energy[i].first;
        int idx = energy[i].second;
        fill(visited.begin(), visited.end(), false);
        visited[idx] = true;
        queue<int> q;
        q.push(idx);
        dist[idx] = 0;
        while (!q.empty()) {
            int tp = q.front(); q.pop();
            FOR(j, g[tp].size()) {
                to = g[tp][j];
                if (visited[to]) continue;
                visited[to] = true;
                q.push(to);
                dist[to] = dist[tp] + 1;
            }
        }
        FOR(j, N) {
            to = energy[j].second;
            if (!visited[to] || energy[j].first > energy[i].first || i == j) continue;
            dp[i] = max(dp[i], dp[j] + energy[i].first - E * dist[to]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
