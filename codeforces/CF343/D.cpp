#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
const double PI = acos(-1.0);
struct Node {
    int l, r;
    ll mx;
    Node() { mx = 0; l = r = -1; }
};
Node tree[100005 * 4];
void build_tree(int ptr, int l, int r) {
    if (l > r) return;
    tree[ptr].l = l; tree[ptr].r = r;
    if (l == r) return;
    int mid = (l + r) / 2;
    build_tree(ptr * 2, l, mid);
    build_tree(ptr * 2 + 1, mid + 1, r);
}
ll query(int ptr, int l, int r) {
    if (tree[ptr].l >= l && tree[ptr].r <= r) {
        return tree[ptr].mx;
    }
    int mid = (tree[ptr].l + tree[ptr].r) / 2;
    if (l > mid) return query(ptr * 2 + 1, l, r);
    else if (r <= mid) return query(ptr * 2, l, r);
    else return max(query(ptr * 2, l, mid), query(ptr * 2 + 1, mid + 1, r));
}
void update(int ptr, int idx, ll val) {
    if (tree[ptr].l == idx && tree[ptr].r == idx) {
        tree[ptr].mx = val;
    }
    else {
        int mid = (tree[ptr].l + tree[ptr].r) / 2;
        if (idx > mid) update(ptr * 2 + 1, idx, val);
        else if (idx <= mid) update(ptr * 2, idx, val);
        tree[ptr].mx = max(tree[ptr * 2].mx, tree[ptr * 2 + 1].mx);
    }
}
int main() {
    int n, r, h;
    scanf("%d", &n);
    vector<pii> vol(n + 1);
    FOR(i, n) {
        scanf("%d %d", &r, &h);
        vol[i + 1] = make_pair((ll)r * (ll)r * (ll)h, -(i + 1));
    }
    sort(vol.begin() + 1, vol.end());
    build_tree(1, 1, n);
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        ll val = query(1, 1, -vol[i].second) + vol[i].first;
        update(1, -vol[i].second, val);
        res = max(res, val);
    }
    printf("%.10lf\n", PI * res);
    return 0;
}
