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

int dp[20][20][1<<10];
string g[20];
const int INF = INT_MAX / 2;
const int dir_x[] = {0, 1, 0, -1};
const int dir_y[] = {-1, 0, 1, 0};
struct Node {
    int r, c, key;
    Node(int _r, int _c, int _key): r(_r), c(_c), key(_key) {}
};

int main() {
    int row, col, t;
    pair<int, int> source, target;
    while (cin >> row >> col >> t) {
        FOR(i, row) cin >> g[i];
        FOR(i, row) FOR(j, col) FOR(k, 1<<10) dp[i][j][k] = INF;
        FOR(i, row) FOR(j, col) {
            if (g[i][j] == '@') { source = make_pair(i, j); g[i][j] = '.'; }
            else if (g[i][j] == '^') { target = make_pair(i, j); g[i][j] = '.'; }
        }
        dp[source.first][source.second][0] = 0;
        queue<Node> q; q.push(Node(source.first, source.second, 0));
        bool ok = false;
        while (!q.empty()) {
            Node tp = q.front(); q.pop();
            if (tp.r == target.first && tp.c == target.second) {
                ok = true;
                // assert(dp[tp.r][tp.c][tp.key] < t);
                cout << dp[tp.r][tp.c][tp.key] << endl;
            }
            FOR(i, 4) {
                int x = tp.r + dir_x[i];
                int y = tp.c + dir_y[i];
                if (x < 0 || x >= row || y < 0 || y >= col) continue;
                if (g[x][y] == '*') continue;
                if (g[x][y] >= 'A' && g[x][y] <= 'J' && (tp.key & (1 << (g[x][y] - 'A'))) == 0) continue;
                int kk = tp.key;
                if (g[x][y] >= 'a' && g[x][y] <= 'j') kk = kk | (1 << (g[x][y] - 'a'));
                if (dp[x][y][kk] > dp[tp.r][tp.c][tp.key] + 1
                    && dp[tp.r][tp.c][tp.key] + 1 < t) {
                    dp[x][y][kk] = dp[tp.r][tp.c][tp.key] + 1;
                    q.push(Node(x, y, kk));
                }
            }
        }
        if (!ok) cout << -1 << endl;
    }
    return 0;
}
