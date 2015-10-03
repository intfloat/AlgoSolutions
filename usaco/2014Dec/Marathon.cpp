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

const int MAX_N = 100005;
vector<pair<int, int> > points;
vector<int> tree;
struct Node {
    int left, right, mxval;
    int lch, rch;
    Node(): lch(-1), rch(-1), mxval(0) {}
};

vector<Node> segtree;
int ptr = 0, N, Q;

int get_dis(pair<int, int>& p1, pair<int, int>& p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int calculate(int pos) {
    // assert(pos > 1 && pos < N);
    return get_dis(points[pos], points[pos - 1])
           + get_dis(points[pos + 1], points[pos])
           - get_dis(points[pos + 1], points[pos - 1]);
}

void build_segtree(int cur, int ll, int rr) {
    if (ll > rr) return;
    segtree[cur].left = ll; segtree[cur].right = rr;
    if (ll == rr) {
        segtree[cur].left = segtree[cur].right = ll;
        segtree[cur].mxval = calculate(ll);
        return;
    }
    int mid = (ll + rr) / 2;
    int ch1 = segtree[cur].lch = ptr++; build_segtree(ptr - 1, ll, mid);
    int ch2 = segtree[cur].rch = ptr++; build_segtree(ptr - 1, mid + 1, rr);
    segtree[cur].mxval = max(segtree[ch1].mxval, segtree[ch2].mxval);
    return;
}

int query_segtree(int cur, int ll, int rr) {
    // assert(rr >= ll);
    // cout << segtree[cur].left << " " << segtree
    // cout << segtree[cur].right << " " << rr << " " << segtree[cur].left << " " << ll << endl;
    // assert(segtree[cur].right >= rr && segtree[cur].left <= ll);
    if (segtree[cur].left == ll && segtree[cur].right == rr) return segtree[cur].mxval;
    if (segtree[cur].left == segtree[cur].right) return segtree[cur].mxval;
    int mid = (segtree[cur].left + segtree[cur].right) / 2;
    if (rr <= mid) return query_segtree(segtree[cur].lch, ll, rr);
    if (ll > mid) return query_segtree(segtree[cur].rch, ll, rr);
    return max(query_segtree(segtree[cur].lch, ll, mid),
               query_segtree(segtree[cur].rch, mid + 1, rr));
}

void update_segtree(int cur, int pos, int val) {
    // assert(segtree[cur].left <= pos && segtree[cur].right >= pos);
    int ll = segtree[cur].left, rr = segtree[cur].right;
    if (ll == rr) {
        segtree[cur].mxval = val;
        return;
    }
    int mid = (ll + rr) / 2;
    int ch1 = segtree[cur].lch, ch2 = segtree[cur].rch;
    if (pos <= mid) update_segtree(segtree[cur].lch, pos, val);
    if (pos > mid) update_segtree(segtree[cur].rch, pos, val);
    segtree[cur].mxval = max(segtree[ch1].mxval, segtree[ch2].mxval);
    return;
}

void add(int pos, int val) {
    for (int i = pos; i < tree.size(); i += (i & (-i)))
        tree[i] += val;
    return;
}

void build_tree() {
    for (int i = 1; i < points.size() - 1; ++i)
        add(i, get_dis(points[i], points[i + 1]));
    return;
}

int query_aux(int pos) {
    int res = 0;
    for (int i = pos; i > 0; i -= (i&(-i)))
        res += tree[i];
    return res;
}

int query(int left, int right) {
    return query_aux(right) - query_aux(left - 1);
}

int main() {
    scanf("%d %d", &N, &Q);
    points.resize(N + 1); tree.resize(N + 1); segtree.resize(3 * N);
    fill(tree.begin(), tree.end(), 0);
    FOR(i, N) scanf("%d %d", &points[i + 1].first, &points[i + 1].second);
    build_tree();
    ptr = 1; build_segtree(0, 2, N - 1);
    FOR(i, Q) {
        char command;
        scanf(" %c", &command);
        if (command == 'U') {
            int p;
            pair<int, int> cc;
            scanf("%d %d %d", &p, &cc.first, &cc.second);
            if (p > 1) add(p - 1, get_dis(cc, points[p - 1]) - get_dis(points[p], points[p - 1]));
            if (p < N) add(p, get_dis(cc, points[p + 1]) - get_dis(points[p + 1], points[p]));
            points[p] = cc;
            if (p - 1 > 1 && p - 1 < N) update_segtree(0, p - 1, calculate(p - 1));
            if (p > 1 && p < N) update_segtree(0, p, calculate(p));
            if (p + 1 > 1 && p + 1 < N) update_segtree(0, p + 1, calculate(p + 1));
        }
        else {
            // assert(command == 'Q');
            int left, right;
            scanf("%d %d", &left, &right);
            int total = query(left, right - 1);
            total = total - query_segtree(0, left + 1, right - 1);
            printf("%d\n", total);
        }
    }
    return 0;
}
