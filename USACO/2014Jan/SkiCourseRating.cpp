#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;
using namespace std;

vector<int> parent, srank, cost;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
};
bool operator<(const Edge& e1, const Edge& e2) {
    return e1.w < e2.w;
}
vector<Edge> edges;
int row, col, T;

int _find(int x) {
    if (parent[x] == x) return x;
    int tmp = parent[x];
    parent[x] = _find(parent[x]);
    if (cost[x] == -1 && cost[tmp] != -1) cost[x] = cost[tmp];
    else if (cost[x] == -1) cost[x] = cost[parent[x]];
    return parent[x];
}

// guarantee x and y are already root node in current set
void _union(int x, int y, const int wei) {
    parent[x] = y;
    if (srank[x] + srank[y] >= T) {
        if (srank[x] < T) { assert(cost[x] == -1); cost[x] = wei; }
        if (srank[y] < T) { assert(cost[y] == -1); cost[y] = wei; }
    }
    srank[y] += srank[x];
    return;
}

int index(int r, int c) {
    return r * col + c;
}

int main() {
    freopen("skilevel.in", "r", stdin);
    freopen("skilevel.out", "w", stdout);
    cin >> row >> col >> T;
    vector<vector<int> > grid(row, vector<int>(col));
    vector<vector<int> > start(row, vector<int>(col));
    FOR(i, row) FOR(j, col) cin >> grid[i][j];
    FOR(i, row) FOR(j, col) cin >> start[i][j];
    ll res = 0;
    parent.resize(row * col);
    srank.resize(row * col);
    cost.resize(row * col);
    FOR(i, parent.size()) parent[i] = i; 
    FOR(i, srank.size()) srank[i] = 1;
    FOR(i, cost.size()) cost[i] = -1;
    FOR(i, row) FOR(j, col) {
        // only consider edges in two directions to avoid duplicate computation
        int cur = index(i, j), that;
        if (i + 1 < row) {
            that = index(i + 1, j);
            edges.push_back(Edge(cur, that, abs(grid[i][j] - grid[i + 1][j])));
        }
        if (j + 1 < col) {
            that = index(i, j + 1);
            edges.push_back(Edge(cur, that, abs(grid[i][j] - grid[i][j + 1])));
        }
    }
    sort(edges.begin(), edges.end());    

    // do union process to find minimum weight to get rank higher than given threshold
    FOR(i, edges.size()) {
        int from = edges[i].u, to = edges[i].v, wei = edges[i].w;
        from = _find(from); to = _find(to);
        if (from == to) continue;        
        _union(from, to, wei);
    }

    FOR(i, row) FOR(j, col) {
        if (start[i][j]) {            
            int idx = index(i, j);
            _find(idx);            
            res += cost[idx];
        }
    }
    cout << res << endl;
    return 0;
}
