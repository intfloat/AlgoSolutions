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
const int MAX_N = 1005;
int fa[MAX_N * MAX_N], S, T;
bool empty[MAX_N][MAX_N];
const int dir_x[] = {1, -1, 0, 0};
const int dir_y[] = {0, 0, 1, -1};
#define CHANGE(r, c) (r * n + c + 1)
int _find(int pos) {
    if (fa[pos] == pos) return pos;
    fa[pos] = _find(fa[pos]);
    return fa[pos];
}
inline void merge(int x, int y) {
    fa[x] = y;
}
void solve() {
    int n, m, res, r, c;
    scanf("%d %d", &n, &m);
    S = 0; T = n * n + 1;
    FOR(i, T + 1) fa[i] = i;
    FOR(i, n + 1) FOR(j, n + 1) empty[i][j] = false;
    bool ok = false;
    FOR(i, m) {
        scanf("%d %d", &r, &c);
        if (ok) continue;
        --r; --c;
        empty[r][c] = true;
        int pos = CHANGE(r, c);
        FOR(j, 4) {
            int nr = r + dir_x[j], nc = c + dir_y[j];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || !empty[nr][nc]) continue;
            int idx = CHANGE(nr, nc);
            merge(_find(pos), _find(idx));
        }
        if (r == 0) merge(_find(S), _find(pos));
        if (r + 1 == n) merge(_find(T), _find(pos));
        if (_find(S) == _find(T)) {
            ok = true;
            res = i + 1;
        }
    }
    if (ok) printf("%d\n", res);
    else printf("-1\n");
}
int main() {
    int TT;
    scanf("%d", &TT);
    FOR(i, TT) {
        solve();
    }
    return 0;
}
