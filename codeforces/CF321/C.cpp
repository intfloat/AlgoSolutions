#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 100005;
const int MAX_M = MAX_N * 2;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], ptr = 0;
inline void addedge(int x, int y) {
    pnt[ptr] = y; nt[ptr] = head[x]; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; head[y] = ptr++;
}
int cat[MAX_N], res = 0;
int n, m, x, y;
void dfs(int pos, int rem, int fa) {
    // assert(rem >= 0);
    bool leaf = true;
    for (int i = head[pos]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to == fa) continue;
        leaf = false;
        if (!cat[to]) dfs(to, m, pos);
        else if (rem - 1 >= 0) dfs(to, rem - 1, pos);
    }
    res += leaf;
}
int main() {
    memset(head, -1, sizeof head);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &cat[i]);
    FOR(i, n - 1) {
        scanf("%d %d", &x, &y);
        addedge(x, y);
    }
    dfs(1, m - cat[1], -1);
    printf("%d\n", res);
    return 0;
}
