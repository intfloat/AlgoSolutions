#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX_N = 50005;
char s[MAX_N], cmd[10];
int N, M;
string res;
struct Node {
    int l, r, inc, d, ch;
    bool same;
    Node() {
        l = r = -1;
        inc = d = 0;
        same = false;
    }
};
Node tree[MAX_N * 4];
void build_tree(int root, int l, int r) {
    if (l > r) return;
    tree[root].l = l; tree[root].r = r;
    if (l == r) {
        tree[root].same = true;
        tree[root].ch = (s[l] - 'A');
        return;
    }
    int mid = (l + r) / 2;
    build_tree(2 * root, l, mid);
    build_tree(2 * root + 1, mid + 1, r);
}
inline void lazy(int root) {
    int mid = (tree[root].l + tree[root].r) / 2;
    if (tree[root].same) {
        tree[root * 2].same = tree[root * 2 + 1].same = true;
        tree[root * 2].ch = tree[root * 2 + 1].ch = tree[root].ch;
        tree[root].same = false;
        tree[root * 2].inc = tree[root].inc;
        tree[root * 2].d = tree[root].d;
        tree[root * 2 + 1].inc = (tree[root].inc + (mid + 1 - tree[root].l) * tree[root].d) % 26;
        tree[root * 2 + 1].d = tree[root].d;
        tree[root].inc = tree[root].d = 0;
    }
    else {
        tree[root * 2].inc += tree[root].inc;
        tree[root * 2].d += tree[root].d;
        tree[root * 2 + 1].inc += (tree[root].inc + (mid + 1 - tree[root].l) * tree[root].d) % 26;
        tree[root * 2 + 1].d += tree[root].d;
        tree[root].inc = tree[root].d = 0;
    }
}
void update1(int root, int l, int r, char ch) {
    if (tree[root].l == l && tree[root].r == r) {
        tree[root].same = true;
        tree[root].ch = (ch - 'A');
        tree[root].inc = tree[root].d = 0;
        return;
    }
    int mid = (tree[root].l + tree[root].r) / 2;
    // need to do lazy propagation
    lazy(root);
    if (r <= mid) update1(root * 2, l, r, ch);
    else if (l >= mid + 1) update1(root * 2 + 1, l, r, ch);
    else {
        update1(root * 2, l, mid, ch);
        update1(root * 2 + 1, mid + 1, r, ch);
    }
}
void update2(int root, int l, int r, int inc, int d) {
    if (tree[root].l == l && tree[root].r == r) {
        tree[root].inc += inc;
        tree[root].d += d;
        return;
    }
    int mid = (tree[root].l + tree[root].r) / 2;
    lazy(root);
    if (r <= mid) update2(root * 2, l, r, inc, d);
    else if (l >= mid + 1) update2(root * 2 + 1, l, r, inc, d);
    else {
        update2(root * 2, l, mid, inc, d);
        update2(root * 2 + 1, mid + 1, r, (inc + (mid + 1 - l) * d) % 26, d);
    }
}
void get(int root) {
    if (tree[root].same) {
        int base = (tree[root].ch + tree[root].inc);
        for (int i = tree[root].l; i <= tree[root].r; ++i) {
            int val = base + (i - tree[root].l) * tree[root].d;
            char cur = (char)(val % 26 + 'A');
            res.push_back(cur);
        }
        return;
    }
    if (tree[root].l == tree[root].r) {
        int val = tree[root].ch + tree[root].inc;
        char cur = (char)(val % 26 + 'A');
        res.push_back(cur);
        return;
    }
    lazy(root);
    get(root * 2);
    get(root * 2 + 1);
}
int main() {
    int root = 1;
    scanf("%d %d", &N, &M);
    scanf("%s", s);
    int type, l, r, delta, ptr = 0;
    char ch;
    build_tree(root, 0, N - 1);
    for (int i = 0; i < M; ++i) {
        scanf("%s %d", cmd, &type);
        if (type == 1) {
            scanf("%d %d %c", &l, &r, &ch);
            --l; --r;
            l = (ptr + l) % N;
            r = (ptr + r) % N;
            if (r < l) {
                update1(root, l, N - 1, ch);
                update1(root, 0, r, ch);
            }
            else update1(root, l, r, ch);
        }
        else if (type == 2) {
            scanf("%d %d %d", &l, &r, &delta);
            --l; --r;
            l = (ptr + l) % N;
            r = (ptr + r) % N;
            if (r < l) {
                update2(root, l, N - 1, delta, 0);
                update2(root, 0, r, delta, 0);
            }
            else update2(root, l, r, delta, 0);
        }
        else if (type == 3) {
            scanf("%d", &delta);
            ptr = (ptr + delta) % N;
        }
        else {
            scanf("%d %d", &l, &r);
            --l; --r;
            if (l > r) continue;
            l = (ptr + l) % N;
            r = (ptr + r) % N;
            if (r < l) {
                update2(root, l, N - 1, 1, 1);
                update2(root, 0, r, N - l + 1, 1);
            }
            else update2(root, l, r, 1, 1);
        }
        // printf("%s\n", res.c_str());
    }
    res.clear(); get(root);
    res = res.substr(ptr, N - ptr) + res.substr(0, ptr);
    printf("%s\n", res.c_str());
    return 0;
}
