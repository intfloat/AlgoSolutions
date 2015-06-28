#include <bits/stdc++.h>
using namespace std;
struct Node {
    int left, right;
    int bound;
};
const int MAX_N = 1800000;
struct SegmentTree {
    vector<Node> tree;
    SegmentTree() {
        tree.resize(MAX_N);
    }
    void build_tree(int root, int l, int r) {
        if (l > r) return;
        tree[root].left = l;
        tree[root].right = r;
        tree[root].bound = 0;
        if (l == r) return;
        int mid = (l + r) / 2;
        build_tree(root * 2, l, mid);
        build_tree(root * 2 + 1, mid + 1, r);
        return;
    }
    void update(int root, int l, int r, int val) {
        if (l > r) return;
        int x = tree[root].left, y = tree[root].right;
        if (x >= l && y <= r) {
            tree[root].bound = max(tree[root].bound, val);
            return;
        }
        int mid = (x + y) / 2;
        if (r <= mid) {
            update(2 * root, l, r, val);
        }
        else if (l > mid) {
            update(2 * root + 1, l, r, val);
        }
        else {
            update(2 * root, l, mid, val);
            update(2 * root + 1, mid + 1, r, val);
        }
        return;
    }
    int query(int root, int pos) {
        int x = tree[root].left, y = tree[root].right;
        if (x == y && x == pos) return tree[root].bound;
        int mid = (x + y) / 2;
        if (pos <= mid) return max(query(2 * root, pos), tree[root].bound);
        else return max(query(2 * root + 1, pos), tree[root].bound);
    }
};
int main() {
    int n, q;
    cin >> n >> q;
    vector<tuple<int, int, char> > arr;
    int x, y;
    char type;
    set<int> st;
    st.insert(0);
    for (int i = 0; i < q; ++i) {
        cin >> x >> y >> type;
        st.insert(x);
        st.insert(y);
        arr.push_back(make_tuple(x, y, type));
    }
    map<int, int> mp;
    vector<int> rmp;
    int idx = 0;
    for (set<int>::iterator it = st.begin(); it != st.end(); ++it) {
        mp[*it] = idx++;
        rmp.push_back(*it);
    }
    SegmentTree row, col;
    int sz = mp.size();
    row.build_tree(1, 0, sz - 1);
    col.build_tree(1, 0, sz - 1);
    int xx, yy, res;
    char cc;
    for (int i = 0; i < q; ++i) {
        xx = mp[get<0>(arr[i])];
        yy = mp[get<1>(arr[i])];
        cc = get<2>(arr[i]);
        if (cc == 'U') {
            res = col.query(1, xx);
            row.update(1, res, yy, xx);
            col.update(1, xx, xx, yy);
            res = rmp[yy] - rmp[res];
            printf("%d\n", res);
        }
        else {
            res = row.query(1, yy);
            col.update(1, res, xx, yy);
            row.update(1, yy, yy, xx);
            res = rmp[xx] - rmp[res];
            printf("%d\n", res);
        }
    }
    return 0;
}
