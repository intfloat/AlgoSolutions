#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef pair<int, int> point;
struct Node {
    int l, r;
    Node(): l(-1), r(-1) {}
};
int main() {
    int N, root = -1, p, d;
    scanf("%d", &N);
    vector<Node> tree(N + 1);
    for (int i = 1; i <= N; ++i) {
        scanf("%d %d", &p, &d);
        if (d == 0) {
            tree[p].l = i;
        }
        else if (d == 1) {
            tree[p].r = i;
        }
        else {
            assert(root == -1);
            root = i;
        }
    }
    vector<point> pos(N + 1);
    queue<int> q;
    pos[root] = make_pair(0, 0);
    q.push(root);
    int mn = 0;
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        mn = min(mn, pos[tp].second);
        int lch = tree[tp].l, rch = tree[tp].r;
        if (lch != -1) {
            pos[lch] = make_pair(pos[tp].first + 2, pos[tp].second - 2);
            q.push(lch);
        }
        if (rch != -1) {
            pos[rch] = make_pair(pos[tp].first + 2, pos[tp].second + 2);
            q.push(rch);
        }
    }
    for (int i = 1; i <= N; ++i) {
        pos[i].second -= mn;
    }
    vector<string> g(50, string(50, ' '));
    for (int i = 1; i <= N; ++i) {
        int r = pos[i].first, c = pos[i].second;
        g[r][c] = (char)('0' + i);
        if (tree[i].l != -1) {
            g[r + 1][c - 1] = '/';
        }
        if (tree[i].r != -1) {
            g[r + 1][c + 1] = '\\';
        }
    }
    FOR(i, g.size()) {
        int ptr = g[i].size() - 1;
        while (ptr >= 0 && g[i][ptr] == ' ') --ptr;
        if (ptr < 0) break;
        g[i].resize(ptr + 1);
        printf("%s\n", g[i].c_str());
    }
    return 0;
}
