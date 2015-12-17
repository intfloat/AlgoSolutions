#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
using namespace std;
struct Node {
    int l, r, d;
    ll sm, mn;
    Node(): l(-1), r(-1), d(0), sm(0), mn(-1) {}
};
const int MAX_N = 200005;
Node tree[MAX_N * 4];
int cnt[MAX_N];
void build_tree(int pos, int low, int up) {
    tree[pos].l = low; tree[pos].r = up;
    if (low == up) {
        tree[pos].mn = tree[pos].sm = cnt[low];
        return;
    }
    int mid = (low + up) / 2;
    build_tree(pos * 2, low, mid);
    build_tree(pos * 2 + 1, mid + 1, up);
    tree[pos].mn = min(tree[pos * 2].mn, tree[pos * 2 + 1].mn);
    tree[pos].sm = tree[pos * 2].sm + tree[pos * 2 + 1].sm;
}
inline void pushdown(int pos) {
    if (tree[pos].d > 0) {
        tree[pos].mn += tree[pos].d;
        tree[pos].sm += (ll)tree[pos].d * (tree[pos].r - tree[pos].l + 1);
        if (tree[pos].r > tree[pos].l) {
            tree[pos * 2].d += tree[pos].d;
            tree[pos * 2 + 1].d += tree[pos].d;
        }
        tree[pos].d = 0;
    }
}
void update(int pos, int low, int up, int delta) {
    pushdown(pos);
    int l = tree[pos].l, r = tree[pos].r;
    if (low == l && up == r) {
        tree[pos].d += delta;
        return;
    }
    int mid = (l + r) / 2;
    if (up <= mid) update(pos * 2, low, up, delta);
    else if (low > mid) update(pos * 2 + 1, low, up, delta);
    else {
        update(pos * 2, low, mid, delta);
        update(pos * 2 + 1, mid + 1, up, delta);
    }
    pushdown(2 * pos); pushdown(2 * pos + 1);
    tree[pos].sm = tree[2 * pos].sm + tree[2 * pos + 1].sm;
    tree[pos].mn = min(tree[pos * 2].mn, tree[pos * 2 + 1].mn);
}
ll query_min(int pos, int low, int up) {
    pushdown(pos);
    int l = tree[pos].l, r = tree[pos].r;
    if (low == l && up == r) {
        return tree[pos].mn;
    }
    int mid = (l + r) / 2;
    if (up <= mid) return query_min(pos * 2, low, up);
    else if (low > mid) return query_min(pos * 2 + 1, low, up);
    else return min(query_min(pos * 2, low, mid), query_min(pos * 2 + 1, mid + 1, up));
}
ll query_sum(int pos, int low, int up) {
    pushdown(pos);
    int l = tree[pos].l, r = tree[pos].r;
    if (low == l && up == r) {
        return tree[pos].sm;
    }
    int mid = (l + r) / 2;
    if (up <= mid) return query_sum(pos * 2, low, up);
    else if (low > mid) return query_sum(pos * 2 + 1, low, up);
    else return query_sum(pos * 2, low, mid) + query_sum(pos * 2 + 1, mid + 1, up);
}
int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int N, Q, low, up, delta;
    char type;
    scanf("%d %d", &N, &Q);
    FOR(i, N) {
        scanf("%d", cnt + i + 1);
    }
    build_tree(1, 1, N);
    FOR(i, Q) {
        scanf(" %c", &type);
        if (type == 'M') {
            scanf("%d %d", &low, &up);
            printf("%lld\n", query_min(1, low, up));
        }
        else if (type == 'P') {
            scanf("%d %d %d", &low, &up, &delta);
            update(1, low, up, delta);
        }
        else {
            assert(type == 'S');
            scanf("%d %d", &low, &up);
            printf("%lld\n", query_sum(1, low, up));
        }
    }
    return 0;
}
