#include <stdio.h>
#include <set>
#include <utility>
#include <queue>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef pair<int, int> point;
const int dir_x[] = {1, 1, 1, 1, -1, -1, -1, -1};
const int dir_y[] = {-1, -1, 1, 1, -1, -1, 1, 1};
const int tx[] = {1, 0, 1, 0, -1, 0, -1, 0};
const int ty[] = {0, -1, 0, 1, 0, -1, 0, 1};
void solve() {
    int row, col, g, x, y;
    scanf("%d %d %d", &row, &col, &g);
    queue<point> q;
    set<point> st;
    point p1, p2;
    FOR(i, g) {
        scanf("%d %d", &x, &y);
        q.push(make_pair(x, y));
        st.insert(make_pair(x, y));
    }
    while (!q.empty()) {
        point tp = q.front(); q.pop();
        FOR(i, 8) {
            x = tp.first + dir_x[i]; y = tp.second + dir_y[i];
            if (x <= 0 || x > row || y <= 0 || y > col) continue;
            p1 = make_pair(x, y);
            p2 = make_pair(tp.first + tx[i], tp.second + ty[i]);
            if (st.find(p1) != st.end() && st.find(p2) == st.end()) {
                st.insert(p2);
                q.push(p2);
            }
        }
    }
    printf("%d\n", st.size());
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
