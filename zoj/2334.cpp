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

const int MAX_N = 100050;
struct Node {
    int l, r, val, dis;
    Node(int _l, int _r, int _v, int _d): l(_l), r(_r), val(_v), dis(_d) {}
    Node() { l = r = val = -1; dis = 0; }
};
Node tree[MAX_N];
int f[MAX_N];

int _find(int x) {
    if (x == f[x]) return x;
    f[x] = _find(f[x]);
    return f[x];
}

int merge(int x, int y) {
    if (x == -1) return y;
    if (y == -1) return x;
    if (tree[x].val < tree[y].val) swap(x, y);
    int res = merge(tree[x].r, y);
    if (res >= 0) f[res] = x;
    tree[x].r = res;
    if (tree[x].r == -1) tree[x].dis = 0;
    else {
        tree[x].dis = tree[tree[x].r].dis + 1;
        if (tree[x].l == -1 || tree[tree[x].r].dis > tree[tree[x].l].dis)
            swap(tree[x].l, tree[x].r);
    }
    return x;
}

int main() {
    int N, M;
    while (cin >> N && N) {
        FOR(i, N) { scanf("%d", &tree[i].val); f[i] = i; tree[i].l = tree[i].r = -1; tree[i].dis = 0; }
        scanf("%d", &M);
        FOR(i, M) {
            int x, y;
            scanf("%d%d", &x, &y);
            --x; --y;
            int px = _find(x), py = _find(y);
            if (px == py) { printf("-1\n"); continue; }

            // process first tree
            tree[px].val /= 2;
            int t = merge(tree[px].l, tree[px].r);
            tree[px].l = tree[px].r = -1;
            t = merge(t, px);

            // process second tree
            tree[py].val /= 2;
            int p = merge(tree[py].l, tree[py].r);
            tree[py].l = tree[py].r = -1;
            p = merge(p, py);

            // merge two trees
            int root = merge(t, p);
            f[x] = f[y] = f[t] = f[p] = root;
            printf("%d\n", tree[root].val);
        }
    }
    return 0;
}
