#include <stdio.h>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
using namespace std;
const int goal = 0b111110111100011000010000001100;
char g[6][6];
const int dir_x[] = {1, -1, 2, -2, 1, -1, 2, -2};
const int dir_y[] = {2, 2, 1, 1, -2, -2, -1, -1};
inline int get(const int cur) {
    return __builtin_popcount((cur >> 5) ^ (goal >> 5));
}
struct Node {
    int status;
    short steps, diff;
    Node(int _status, int _steps): status(_status), steps(_steps) {
        diff = get(_status);
    }
    bool operator<(const Node& that) const {
        return steps > that.steps;
    }
};
inline void solve() {
    int start = 0, blank;
    for (int i = 0; i < 5; ++i) {
        scanf("%s", g[i]);
        for (int j = 0; j < 5; ++j) {
            start <<= 1;
            if (g[i][j] == '1') {
                start += 1;
            }
            else if (g[i][j] == '*') {
                blank = i * 5 + j;
            }
        }
    }
    set<int> visited;
    start = ((start << 5) | blank);
    priority_queue<Node> q;
    q.push(Node(start, 0));
    visited.insert(start);
    int x, y, nx, ny, nstatus;
    while (!q.empty()) {
        Node tp = q.top();
        q.pop();
        if (tp.steps > 15) {
            printf("-1\n");
            return;
        }
        if (tp.status == goal) {
            printf("%d\n", tp.steps);
            return;
        }
        blank = ((tp.status) & 31);
        int st = tp.status >> 5;
        x = blank / 5;
        y = blank % 5;
        for (int i = 0; i < 8; ++i) {
            nx = x + dir_x[i];
            ny = y + dir_y[i];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            nstatus = st & (~(1 << (24 - 5 * nx - ny)));
            if (st & (1 << (24 - 5 * nx - ny))) {
                nstatus |= (1 << (24 - blank));
            }
            else {
                nstatus = nstatus & (~(1 << (24 - blank)));
            }
            nstatus = (nstatus << 5) | (5 * nx + ny);
            if (visited.find(nstatus) != visited.end() || tp.steps + 1 + get(nstatus) > 15) {
                continue;
            }
            visited.insert(nstatus);
            q.push(Node(nstatus, tp.steps + 1));
        }
    }
    printf("-1\n");
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
