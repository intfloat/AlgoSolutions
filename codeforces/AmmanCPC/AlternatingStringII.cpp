#include <bits/stdc++.h>
using namespace std;
struct Node {
    int l, r, val;
    Node() {
        val = INT_MAX;
    }
};
Node tree[400005];
void build_tree(int root, int low, int up) {
    if (low > up) return;
    tree[root].l = low;
    tree[root].r = up;
    tree[root].val = INT_MAX;
    if (low == up) {
        return;
    }
    int mid = (low + up) / 2;
    build_tree(2 * root, low, mid);
    build_tree(2 * root + 1, mid + 1, up);
}
void update(int root, int val, int idx) {
    if (tree[root].l == idx && tree[root].r == idx) {
        tree[root].val = min(tree[root].val, val);
        return;
    }
    int mid = (tree[root].l + tree[root].r) / 2;
    if (idx <= mid) {
        update(2 * root, val, idx);
        tree[root].val = min(tree[root].val, tree[2 * root].val);
    }
    else {
        update(2 * root + 1, val, idx);
        tree[root].val = min(tree[root].val, tree[2 * root + 1].val);
    }
}
int query(int root, int low, int up) {
    if (tree[root].l == low && tree[root].r == up) {
        return tree[root].val;
    }
    int mid = (tree[root].l + tree[root].r) / 2;
    if (up <= mid) {
        return query(2 * root, low, up);
    }
    else if (low > mid) {
        return query(2 * root + 1, low, up);
    }
    else {
        return min(query(2 * root, low, mid), query(2 * root + 1, mid + 1, up));
    }
}
inline void solve() {
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    vector<int> dp(n);
    dp[n - 1] = 0;
    vector<int> pos;
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] == s[i]) {
            pos.push_back(i);
        }
    }
    build_tree(1, 0, n - 1);
    update(1, 0, n - 1);
    vector<int>::iterator it;
    for (int i = n - 2; i >= 0; --i) {
        dp[i] = dp[i + 1] + 1;
        int up = min(i + k - 1, n - 1);
        it = lower_bound(pos.begin(), pos.end(), i + 1);
        if (it == pos.end() || *it > up) {
            update(1, dp[i], i);
        }
        else {
            if (up == n - 1) {
                dp[i] = 0;
            }
            else {
                dp[i] = min(dp[i], query(1, *it + 1, up + 1) + 1);
            }
            update(1, dp[i], i);
        }
    }
    cout << dp[0] << endl;
    return;
}
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
