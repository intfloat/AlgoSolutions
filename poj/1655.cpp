#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX_N = 20005;
const int MAX_M = 2 * MAX_N;
int ptr, head[MAX_N], pnt[MAX_M], nt[MAX_M], N;
inline void addedge(int x, int y) {
    pnt[ptr] = y; nt[ptr] = head[x]; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; head[y] = ptr++;
}
int tson[MAX_N], mson[MAX_N];
int dfs(int pos, int fa) {
    for (int i = head[pos]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (fa == to) {
            continue;
        }
        int cur = dfs(to, pos);
        mson[pos] = max(mson[pos], cur);
        tson[pos] += cur;
    }
    ++tson[pos];
    mson[pos] = max(mson[pos], N - tson[pos]);
    return tson[pos];
}
inline void solve() {
    int x, y;
    scanf("%d", &N);
    ptr = 0;
    for (int i = 0; i <= N; ++i) {
        head[i] = -1;
        tson[i] = mson[i] = 0;
    }
    for (int i = 0; i < N - 1; ++i) {
        scanf("%d %d", &x, &y);
        addedge(x, y);
    }
    dfs(1, -1);
    int res = -1, mx = MAX_N;
    for (int i = 1; i <= N; ++i) {
        if (mson[i] < mx) {
            mx = mson[i];
            res = i;
        }
    }
    printf("%d %d\n", res, mx);
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
