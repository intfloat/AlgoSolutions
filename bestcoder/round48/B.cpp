#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define WHITE 0
#define BLACK 1
#define UNK 2
using namespace std;
typedef long long ll;
const int MAX_N = 200005;
int head[MAX_N], pnt[MAX_N], nt[MAX_N], color[MAX_N];
int ptr, c1, c2, res, n, m;
bool ok;
inline void addedge(int x, int y) {
    pnt[ptr] = y; nt[ptr] = head[x]; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; head[y] = ptr++;
}
void dfs(int idx, int cc) {
    color[idx] = cc;
    c1 += (cc == WHITE);
    c2 += (cc == BLACK);
    for (int i = head[idx]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (color[to] == UNK) {
            dfs(to, !cc);
        }
        else if (color[to] == cc) {
            ok = false;
            return;
        }
        if (!ok) return;
    }
}
inline void solve() {
    scanf("%d %d", &n, &m);
    FOR(i, n) {
        head[i] = -1;
        color[i] = UNK;
    }
    res = ptr = 0;
    ok = true;
    int x, y;
    FOR(i, m) {
        scanf("%d %d", &x, &y);
        --x; --y;
        addedge(x, y);
    }
    if (n <= 1) {
        printf("Poor wyh\n");
        return;
    }
    FOR(i, n) {
        if (color[i] == UNK) {
            c1 = c2 = 0;
            dfs(i, WHITE);
            res += max(c1, c2);
            if (!ok) {
                printf("Poor wyh\n");
                return;
            }
        }
    }
    res = min(res, n - 1);
    printf("%d %d\n", res, n - res);
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
