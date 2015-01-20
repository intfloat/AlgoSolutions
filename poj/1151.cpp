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
using namespace std;

struct Node {
    double total;
    int left, right, lc, rc, cnt;   
    Node() {
        total = cnt = 0;
        left = right = lc = rc = -1;        
    }
};
Node tree[1500];

struct Line {
    double x, y1, y2;
    bool left;
    Line(double _x, double _y1, double _y2, bool _left): x(_x), y1(_y1), y2(_y2), left(_left) {}
};

bool cmp(const Line& i, const Line& j) { return i.x < j.x; }

int n, ptr;
vector<Line> lines;
vector<double> ys;

int get(double y) {
    for (int i = 0; i < ys.size(); ++i) {
        if (fabs(y - ys[i]) < 1e-6) return i;
    }
    assert(false); // should not reach here
    return -1;
}

void build_tree(int low, int up, int cur) {
    tree[cur].left = low;
    tree[cur].right = up;
    if (up - low <= 1) return;
    int mid = (low + up) / 2;
    ++ptr; tree[cur].lc = ptr;
    build_tree(low, mid, ptr);
    ++ptr; tree[cur].rc = ptr;
    build_tree(mid, up, ptr);
    return;
}

void update_node(int root) {
    if (tree[root].cnt > 0) {
        tree[root].total = ys[tree[root].right] - ys[tree[root].left];
        return;
    }
    if (tree[root].right - tree[root].left <= 1) {
        tree[root].total = 0;
        return;
    }
    else {
        tree[root].total = tree[tree[root].lc].total + tree[tree[root].rc].total;
        return;
    }
}

void insert_node(int low, int up, int cur) {
    // cout << "insert: " << low << " " << up << " " << cur << endl;
    if (low <= tree[cur].left && up >= tree[cur].right) {
        ++tree[cur].cnt;
        update_node(cur);
        return;
    }
    assert(tree[cur].right - tree[cur].left > 1);
    int mid = (tree[cur].left + tree[cur].right) / 2;
    if (up <= mid) { insert_node(low, up, tree[cur].lc); }
    else if (low >= mid) { insert_node(low, up, tree[cur].rc); }
    else {
        insert_node(low, mid, tree[cur].lc);
        insert_node(mid, up, tree[cur].rc);
    }
    update_node(cur);
    return;
}

void delete_node(int low, int up, int cur) {
    if (low <= tree[cur].left && up >= tree[cur].right) {
        assert(tree[cur].cnt > 0);
        --tree[cur].cnt;
        update_node(cur);
        return;
    }
    assert(tree[cur].right - tree[cur].left > 1);
    int mid = (tree[cur].left + tree[cur].right) / 2;
    if (up <= mid) { delete_node(low, up, tree[cur].lc); }
    else if (low >= mid) { delete_node(low, up, tree[cur].rc); }
    else {
        delete_node(low, mid, tree[cur].lc);
        delete_node(mid, up, tree[cur].rc);
    }
    update_node(cur);
    return;
}

int main() {
    int t = 1;
    while (cin >> n && n) {
        double x1, y1, x2, y2;
        lines.clear(); ys.clear(); ptr = 0;
        for (int i = 0; i < 1500; ++i) {
            tree[i].total = tree[i].cnt = 0;
            tree[i].left = tree[i].right = tree[i].lc = tree[i].rc = -1;
        }
        for (int i = 0; i < n; ++i) {
            cin >> x1 >> y1 >> x2 >> y2;
            lines.push_back(Line(x1, y1, y2, true));
            lines.push_back(Line(x2, y1, y2, false));
            ys.push_back(y1); ys.push_back(y2);
        }
        sort(lines.begin(), lines.end(), cmp);
        sort(ys.begin(), ys.end());
        double area = 0;
        build_tree(0, ys.size(), 0);
        for (int i = 0; i + 1 < lines.size(); ++i) {
            Line tmp = lines[i];
            if (tmp.left) insert_node(get(tmp.y1), get(tmp.y2), 0);
            else delete_node(get(tmp.y1), get(tmp.y2), 0);
            area += tree[0].total * (lines[i + 1].x - tmp.x);
        }
        cout << "Test case #" << t++ << endl;
        cout << "Total explored area: " << fixed << setprecision(2) << area << endl;
        cout << endl;
    }
    return 0;
}
