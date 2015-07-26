#pragma comment(linker, "/STACK:102400000,102400000")
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <string.h>
#define UNK 2
#define BLACK 0
#define WHITE 1
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
const int MAX_N = 10005;
const int MAX_M = 200005;
int color[MAX_N], c1, c2, ptr;
int pnt[MAX_M], head[MAX_N], nt[MAX_M];
vector<int> arr;
inline void addedge(int u, int v) {
    pnt[ptr] = v; nt[ptr] = head[u]; head[u] = ptr++;
    pnt[ptr] = u; nt[ptr] = head[v]; head[v] = ptr++;
}
void dfs(int idx, int val) {
    if (val == BLACK) ++c1;
    else ++c2;
    color[idx] = val;
    for (int i = head[idx]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (color[to] == UNK) {
            dfs(to, !val);
        }
    }
}
inline void solve() {
    ptr = 0;
    arr.clear();
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    FOR(i, n) {
        color[i] = UNK;
        head[i] = -1;
    }
    FOR(i, m) {
        scanf("%d %d", &x, &y);
        --x; --y;
        addedge(x, y);
    }
    FOR(i, n) {
        if (color[i] == UNK) {
            c1 = c2 = 0;
            dfs(i, BLACK);
            arr.push_back(abs(c1 - c2));
        }
    }
    sort(arr.begin(), arr.end(), greater<int>());
    int d = 0;
    FOR(i, arr.size()) {
        if (d > 0) d -= arr[i];
        else d += arr[i];
    }
    int res = (n - d) / 2;
    printf("%d\n", res * (n - res) - m);
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
