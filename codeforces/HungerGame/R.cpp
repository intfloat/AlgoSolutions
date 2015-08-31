#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
    bool operator<(const Edge& that) const {
        return w < that.w;
    }
};
vector<Edge> g;
int n, m;
vector<int> fa;
inline int _find(int pos) {
    if (fa[pos] == pos) {
        return pos;
    }
    fa[pos] = _find(fa[pos]);
    return fa[pos];
}
inline void merge(int x, int y) {
    fa[x] = y;
}
inline ll get(vector<Edge>& arr) {
    ll ret = 0;
    for (int i = 0; i < arr.size(); ++i) {
        int rx = _find(arr[i].u), ry = _find(arr[i].v);
        if (rx != ry) {
            merge(rx, ry);
            ret += arr[i].w;
        }
    }
    return ret;
}
inline bool check(int mid) {
    vector<Edge> arr;
    for (int i = 0; i <= mid; ++i) {
        arr.push_back(g[i]);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
    }
    // minimum spanning tree
    ll mn = get(arr);
    // maximum spanning tree
    reverse(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
    }
    ll mx = get(arr);
    return (mn != mx);
}
int main() {
    int x, y, wei;
    scanf("%d %d", &n, &m);
    fa.resize(n);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &x, &y, &wei);
        --x; --y;
        g.push_back(Edge(x, y, wei));
    }
    int l = 0, r = m - 1;
    string res(m, '0');
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (l < m && !check(l)) ++l;
    for (int i = l; i < m; ++i) {
        res[i] = '1';
    }
    printf("%s\n", res.c_str());
    return 0;
}
