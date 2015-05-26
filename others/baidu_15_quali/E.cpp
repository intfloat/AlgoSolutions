// greedy algorithm got wrong answer...
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <utility>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int dir_x[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dir_y[] = {-2, 2, -2, 2, -1, 1, -1, 1};
const pair<int, int> INF = make_pair(5000, 5000);
void solve() {
    int row, col, K, x1, x2, y1, y2;
    scanf("%d %d %d", &row, &col, &K);
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    // one step reachable is a special case
    FOR(j, 8) {
        int nx = x2 + dir_x[j];
        int ny = y2 + dir_y[j];
        if (nx < 1 || nx > row || ny < 1 || ny > col) continue;
        int dx = abs(x1 - nx), dy = abs(y1 - ny);
        if (max(dx, dy) == 1) {
            printf("1\n");
            return;
        }
    }
    for (int i = 1; i <= K; ++i) {
        pair<int, int> mn = INF, nt;
        FOR(j, 8) {
            int nx = x2 + dir_x[j];
            int ny = y2 + dir_y[j];
            if (nx < 1 || nx > row || ny < 1 || ny > col) continue;
            int dx = abs(x1 - nx), dy = abs(y1 - ny);
            pair<int, int> cur = make_pair(max(dx, dy), min(dx, dy));
            if (i > 1 && max(dx, dy) <= i) {
                printf("%d\n", i);
                return;
            }
            if (cur < mn) {
                nt = make_pair(nx, ny);
                mn = cur;
            }
        }
        assert(mn != INF);
        x2 = nt.first; y2 = nt.second;
    }
    printf("OH,NO!\n");
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        printf("Case #%d:\n", tt + 1);
        solve();
    }
    return 0;
}
