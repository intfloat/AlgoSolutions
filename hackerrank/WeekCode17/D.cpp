#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<pair<int, int>, int> point;
const int MAX_N = 100005;
struct Node {
    int l, r;
    ll mx;
    Node() {
        l = r = -1;
        mx = -1e16;
    }
};
Node tree[MAX_N * 4];
void build_tree(int root, int low, int up) {
    if (low > up) return;
    tree[root].l = low;
    tree[root].r = up;
    if (low == up) {
        return;
    }
    int mid = (low + up) / 2;
    build_tree(2 * root, low, mid);
    build_tree(2 * root + 1, mid + 1, up);
}
void update(int root, ll val, int pos) {
    if (tree[root].l == tree[root].r) {
        tree[root].mx = val;
        return;
    }
    int mid = (tree[root].l + tree[root].r) / 2;
    if (pos <= mid) update(2 * root, val, pos);
    else update(2 * root + 1, val, pos);
    tree[root].mx = -1e16;
    if (tree[root].l >= 0) tree[root].mx = max(tree[root].mx, tree[2 * root].mx);
    if (tree[root].r >= 0) tree[root].mx = max(tree[root].mx, tree[2 * root + 1].mx);
}
ll query(int root, int low, int up) {
    if (low <= tree[root].l && up >= tree[root].r) {
        return tree[root].mx;
    }
    int mid = (tree[root].l + tree[root].r) / 2;
    if (up <= mid) return query(root * 2, low, up);
    if (low >= mid + 1) return query(root * 2 + 1, low, up);
    return max(query(root * 2, low, mid), query(root * 2 + 1, mid + 1, up));
}
multiset<ll> cnt[MAX_N];
int main() {
    int N, H, dh, dw, x, y, z;
    scanf("%d %d %d %d", &N, &H, &dh, &dw);
    vector<point> arr;
    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d", &y, &x, &z);
        arr.push_back(make_pair(make_pair(y, x), z));
    }
    sort(arr.begin(), arr.end());
    build_tree(1, 0, MAX_N);
    vector<ll> res(N, -1e16);
    int leave = 0, enter = 0;
    multiset<ll>::iterator it;
    ll goal = -1e16;
    for (int i = 0; i < N; ++i) {
        int xx = arr[i].first.second, yy = arr[i].first.first;
        if (yy <= dh) {
            res[i] = max(res[i], (ll)arr[i].second);
        }
        while (enter < N && arr[enter].first.first < yy) {
            int nx = arr[enter].first.second;
            cnt[nx].insert(res[enter]);
            update(1, *cnt[nx].rbegin(), nx);
            ++enter;
        }
        while (leave < N && arr[leave].first.first + dh < yy) {
            int nx = arr[leave].first.second;
            it = cnt[nx].find(res[leave]);
            assert(it != cnt[nx].end());
            cnt[nx].erase(it);
            if (cnt[nx].empty()) update(1, -1e16, nx);
            else update(1, *cnt[nx].rbegin(), nx);
            ++leave;
        }
        int l = max(0, xx - dw), r = min(xx + dw, MAX_N - 2);
        res[i] = max(res[i], query(1, l, r) + arr[i].second);
        if (yy + dh >= H) {
            goal = max(goal, res[i]);
        }
    }
    printf("%lld\n", goal);
    return 0;
}
