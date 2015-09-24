#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int g = 29;
const ll MOD = (ll)(1e9 + 7);
char s[100005];
int n, m, k;
struct Node {
    int l, r, val;
    ll h;
    Node(): l(-1), r(-1), val(-1) {}
};
const int MAX_N = 400000;
Node tree[MAX_N];
ll pw[MAX_N / 2], dp[MAX_N / 2];
inline void preprocess() {
    pw[0] = 1; dp[0] = 1;
    for (int i = 1; i < MAX_N / 2; ++i) {
        pw[i] = (pw[i - 1] * g) % MOD;
        dp[i] = (dp[i - 1] + pw[i]) % MOD;
    }
}
inline ll get(int low, int up) {
    assert(low <= up);
    ll ret = (dp[up] - dp[low - 1]) % MOD;
    if (ret < 0) ret = (ret + MOD) % MOD;
    return ret;
}
void build_tree(int root, int low, int up) {
    tree[root].l = low; tree[root].r = up;
    if (low == up) {
        tree[root].val = (s[low] - '0');
        tree[root].h = ((s[low] - '0') * get(low, up)) % MOD;
        return;
    }
    int mid = (low + up) / 2;
    build_tree(2 * root, low, mid);
    build_tree(2 * root + 1, mid + 1, up);
    tree[root].h = (tree[2 * root].h + tree[2 * root + 1].h) % MOD;
}
inline void lazy(int root) {
    if (tree[root].val < 0 || tree[root].l == tree[root].r) return;
    int mid = (tree[root].l + tree[root].r) / 2;
    tree[root * 2].val = tree[root].val;
    tree[root * 2].h = (tree[root].val * get(tree[root].l, mid)) % MOD;
    tree[root * 2 + 1].val = tree[root].val;
    tree[root * 2 + 1].h = (tree[root].val * get(mid + 1, tree[root].r)) % MOD;
    tree[root].val = -1;
}
ll query(int root, int low, int up) {
    if (tree[root].l == low && tree[root].r == up) {
        return tree[root].h;
    }
    lazy(root);
    int mid = (tree[root].l + tree[root].r) / 2;
    if (up <= mid) return query(root * 2, low, up);
    else if (low > mid) return query(2 * root + 1, low, up);
    else return (query(2 * root, low, mid) + query(2 * root + 1, mid + 1, up)) % MOD;
}
void update(int root, int low, int up, int nv) {
    if (tree[root].l == low && tree[root].r == up) {
        tree[root].val = nv;
        tree[root].h = (nv * get(low, up)) % MOD;
        return;
    }
    lazy(root);
    int mid = (tree[root].l + tree[root].r) / 2;
    if (up <= mid) update(2 * root, low, up, nv);
    else if (low > mid) update(2 * root + 1, low, up, nv);
    else {
        update(2 * root, low, mid, nv);
        update(2 * root + 1, mid + 1, up, nv);
    }
    tree[root].h = (tree[2 * root].h + tree[2 * root + 1].h) % MOD;
}
int main() {
    preprocess();
    int type, l, r, d;
    scanf("%d %d %d", &n, &m, &k);
    scanf("%s", s + 1);
    build_tree(1, 1, n);
    for (int i = 0; i < m + k; ++i) {
        scanf("%d %d %d %d", &type, &l, &r, &d);
        if (type == 1) {
            update(1, l, r, d);
        }
        else {
            if (d == (r - l + 1)) { printf("YES\n"); continue; }
            ll h1 = (query(1, l, r - d) * pw[d]) % MOD;
            ll h2 = query(1, l + d, r);
            if (h1 == h2) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
    }
    return 0;
}
