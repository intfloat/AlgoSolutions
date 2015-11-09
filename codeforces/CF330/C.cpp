#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct Node {
    int pos, id;
    Node(int _pos, int _id): pos(_pos), id(_id) {}
    bool operator<(const Node& that) const {
        return pos < that.pos;
    }
};
vector<Node> xarr, yarr;
int n, k;
vector<int> sp(4);
ll res = ~(1ll << 63);
void dfs(int idx, int rem) {
    if (idx == 4) {
        if (rem != 0) return;
        set<int> select;
        vector<int> val = sp;
        int ptr = 0;
        while (val[0] > 0) {
            if (select.find(xarr[ptr].id) == select.end()) {
                --val[0]; select.insert(xarr[ptr].id);
            }
            ++ptr;
        }
        while (select.find(xarr[ptr].id) != select.end()) ++ptr;
        ll x1 = xarr[ptr].pos;

        ptr = xarr.size() - 1;
        while (val[1] > 0) {
            if (select.find(xarr[ptr].id) == select.end()) {
                --val[1]; select.insert(xarr[ptr].id);
            }
            --ptr;
        }
        while (select.find(xarr[ptr].id) != select.end()) --ptr;
        ll x2 = xarr[ptr].pos;

        ptr = 0;
        while (val[2] > 0) {
            if (select.find(yarr[ptr].id) == select.end()) {
                --val[2]; select.insert(yarr[ptr].id);
            }
            ++ptr;
        }
        while (select.find(yarr[ptr].id) != select.end()) ++ptr;
        ll y1 = yarr[ptr].pos;

        ptr = yarr.size() - 1;
        while (val[3] > 0) {
            if (select.find(yarr[ptr].id) == select.end()) {
                --val[3]; select.insert(yarr[ptr].id);
            }
            --ptr;
        }
        while (select.find(yarr[ptr].id) != select.end()) --ptr;
        ll y2 = yarr[ptr].pos;
        if (x1 == x2) x2 += 2;
        if (y1 == y2) y2 += 2;
        if ((x2 - x1) % 2) ++x2;
        if ((y2 - y1) % 2) ++y2;
        res = min(res, (x2 - x1) * (y2 - y1) / 4);
        return;
    }
    FOR(i, rem + 1) {
        sp[idx] = i;
        dfs(idx + 1, rem - i);
    }
}
int main() {
    int x1, x2, y1, y2;
    scanf("%d %d", &n, &k);
    FOR(i, n) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        xarr.push_back(Node(x1 + x2, i));
        yarr.push_back(Node(y1 + y2, i));
    }
    sort(xarr.begin(), xarr.end());
    sort(yarr.begin(), yarr.end());
    dfs(0, k);
    cout << res << endl;
    return 0;
}
