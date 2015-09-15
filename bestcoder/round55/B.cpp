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
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char g[55][55];
const int dir_x[] = {1, -1, 0, 0};
const int dir_y[] = {0, 0, -1, 1};
inline int get(pii& a, pii& b) {
    int diff = abs(a.first - b.first) + abs(a.second - b.second);
    if (diff != 1) return INT_MAX / 2;
    return abs(g[a.first][a.second] - g[b.first][b.second]);
}
inline void solve() {
    int row, col, K, x1, y1, x2, y2;
    scanf("%d %d %d", &row, &col, &K);
    FOR(i, row) scanf("%s", g[i]);
    scanf("%d %d", &x1, &y1);
    --x1; --y1;
    scanf("%d %d", &x2, &y2);
    --x2; --y2;
    assert(g[x1][y1] != '#');
    assert(g[x2][y2] != '#');
    if (K == 0) {
        printf("No Answer\n");
        return;
    }
    bool ok[55][55];
    int step[55][55];
    memset(ok, false, sizeof ok);
    memset(step, -1, sizeof step);
    queue<pii> q;
    ok[x1][y1] = true; step[x1][y1] = 0;
    q.push(make_pair(x1, y1));
    vector<pii> arr;
    map<pii, int> mp;
    while (!q.empty()) {
        pii tp = q.front(); q.pop();
        arr.push_back(tp); mp[tp] = arr.size() - 1;
        int x = tp.first, y = tp.second;
        FOR(i, 4) {
            int nx = x + dir_x[i], ny = y + dir_y[i];
            if (nx < 0 || nx >= row || ny < 0 || ny >= col || g[nx][ny] == '#') continue;
            if (ok[nx][ny]) continue;
            if (step[x][y] + 1 >= K) continue;
            q.push(make_pair(nx, ny));
            step[nx][ny] = step[x][y] + 1;
            ok[nx][ny] = true;
        }
    }
    if (!ok[x2][y2]) {
        printf("No Answer\n");
        return;
    }
    double dis[3000][51];
    bool visited[3000][51];
    memset(visited, false, sizeof visited);
    FOR(i, 3000) FOR(j, 51) dis[i][j] = 1e12;
    dis[0][K] = 0;
    double res = 1e12;
    priority_queue<pair<double, pii> > pq;
    pq.push(make_pair(0, make_pair(0, K)));
    while (!pq.empty()) {
        pair<double, pii> tp;
        int pos = -1, rem = -1;
        bool flag = false;
        while (!pq.empty()) {
            tp = pq.top(); pq.pop();
            pos = tp.second.first, rem = tp.second.second;
            if (visited[pos][rem]) continue;
            else { flag = true; break; }
        }
        if (!flag) break;
        if (arr[pos] == make_pair(x2, y2)) {
            res = min(res, dis[pos][rem]);
            break;
        }
        visited[pos][rem] = true;
        if (rem <= 1) continue;
        FOR(i, 4) {
            int nx = arr[pos].first + dir_x[i];
            int ny = arr[pos].second + dir_y[i];
            pii tmp = make_pair(nx, ny);
            if (mp.find(tmp) == mp.end()) continue;
            int idx = mp[tmp];
            if (!visited[idx][rem - 1]) {
                double nd = dis[pos][rem] + 1.0 * get(arr[idx], arr[pos]) / rem;
                if (nd < dis[idx][rem - 1]) {
                    dis[idx][rem - 1] = nd;
                    pq.push(make_pair(-nd, make_pair(idx, rem - 1)));
                }
            }
        }
    }
    cout << fixed << setprecision(2) << res << endl;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
