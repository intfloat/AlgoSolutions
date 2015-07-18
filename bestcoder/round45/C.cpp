#include <stdio.h>
#include <stack>
#include <string.h>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
const int MAX_N = 201000;
int ptr, total, n, q;
int head[MAX_N / 2], pnt[MAX_N], nt[MAX_N], tree[MAX_N];
int p[MAX_N / 2][18], depth[MAX_N / 2];
void addedge(int u, int v) {
    pnt[ptr] = v; nt[ptr] = head[u]; head[u] = ptr++;
    pnt[ptr] = u; nt[ptr] = head[v]; head[v] = ptr++;
}
bool visited[MAX_N / 2];
int st[MAX_N / 2], ed[MAX_N / 2], val[MAX_N / 2];
void dfs(int root) {
    stack<int> q;
    q.push(root);
    while (!q.empty()) {
        int tp = q.top(); q.pop();
        if (visited[tp]) {
            ed[tp] = ++total;
            continue;
        }
        q.push(tp);
        visited[tp] = true;
        st[tp] = ++total;
        for (int i = head[tp]; i != -1; i = nt[i]) {
            int to = pnt[i];
            if (!visited[to]) {
                depth[to] = depth[tp] + 1;
                p[to][0] = tp;
                q.push(to);
            }
        }
    }
}
void update(int pos, int v) {
    while (pos <= total) {
        tree[pos] ^= v;
        pos += (pos & (-pos));
    }
}
int query(int pos) {
    int ret = 0;
    while (pos > 0) {
        ret ^= tree[pos];
        pos -= (pos & (-pos));
    }
    return ret;
}
inline int lca(int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);
    int diff = depth[x] - depth[y];
    FOR(i, 18) {
        if ((1 << i) & diff) {
            x = p[x][i];
        }
    }
    if (x == y) return x;
    for (int i = 17; i >= 0; --i) {
        if (p[x][i] != p[y][i]) {
            x = p[x][i];
            y = p[y][i];
        }
    }
    return p[x][0];
}
void solve() {
    int x, y, type;
    scanf("%d %d", &n, &q);
    ptr = total = 0;
    FOR(i, n) head[i] = -1;
    FOR(i, n - 1) {
        scanf("%d %d", &x, &y);
        --x; --y;
        addedge(x, y);
    }
    memset(visited, false, sizeof visited);
    memset(tree, 0, sizeof tree);
    memset(depth, 0, sizeof depth);
    p[0][0] = 0; dfs(0);
    for (int i = 1; i < 18; ++i) {
        for (int j = 0; j < n; ++j) {
            p[j][i] = p[p[j][i - 1]][i - 1];
        }
    }
    FOR(i, n) {
        scanf("%d", &val[i]); ++val[i];
        update(st[i], val[i]);
        update(ed[i], val[i]);
    }
    FOR(i, q) {
        scanf("%d %d %d", &type, &x, &y);
        if (type == 0) {
            --x; ++y;
            update(st[x], val[x] ^ y);
            update(ed[x], val[x] ^ y);
            val[x] = y;
        }
        else {
            --x; --y;
            int res = query(st[x]) ^ query(st[y]) ^ val[lca(x, y)];
            if (res == 0) printf("-1\n");
            else printf("%d\n", res - 1);
        }
    }
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) solve();
    return 0;
}
