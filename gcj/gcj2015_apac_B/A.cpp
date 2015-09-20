#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> point;
const int INF = INT_MAX / 2;
vector<int> cost[505][505];
void solve() {
    int N, M, K, x, y, c;
    scanf("%d %d %d", &N, &M, &K);
    FOR(i, N + 1) FOR(j, N + 1) cost[i][j].clear();
    FOR(i, M) {
        scanf("%d %d", &x, &y);
        FOR(j, 24) {
            scanf("%d", &c);
            cost[x][y].push_back(c);
            cost[y][x].push_back(c);
        }
    }
    int dis[505][24];
    FOR(i, N + 1) FOR(j, 24) dis[i][j] = INF;
    FOR(start, 24) {
        // spfa
        vector<bool> inq(N + 1, false);
        dis[1][start] = 0; inq[1] = true;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int tp = q.front(); q.pop(); inq[tp] = false;
            for (int i = 1; i <= N; ++i) {
                if (cost[tp][i].empty()) continue;
                int md = (start + dis[tp][start]) % 24;
                if (dis[i][start] > dis[tp][start] + cost[tp][i][md]) {
                    dis[i][start] = dis[tp][start] + cost[tp][i][md];
                    if (!inq[i]) { q.push(i); inq[i] = true; }
                }
            }
        }
    }
    int D, S;
    FOR(i, K) {
        scanf("%d %d", &D, &S);
        if (dis[D][S] == INF) {
            cout << " -1";
        }
        else cout << " " << dis[D][S];
    }
    cout << endl;
    return;
}
int main() {
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ":";
        solve();
    }
    return 0;
}
