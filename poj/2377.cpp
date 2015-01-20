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
using namespace std;

class Edge {
public:
    int from, to, cost; 
};
bool cmp(const Edge& x, const Edge& y) {
    return x.cost > y.cost;
}
Edge edge[20005];

class UF {
    int p[1005];
public:
    UF() { for (int i = 0; i < 1005; ++i) p[i] = i; }
    int _find(int x) {
        if (p[x] == x) return x;
        else p[x] = _find(p[x]);
        return p[x];
    }

    bool _union(int x, int y) {
        int px = _find(x);
        int py = _find(y);
        if (px != py) { p[px] = py; return true; }
        return false;
    }
};
UF uf;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) 
        scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].cost);
    long long res = 0;
    sort(edge, edge + m, cmp);
    int conn = 0;
    for (int i = 0; i < m; ++i) {
        int ok = uf._union(edge[i].from, edge[i].to);
        if (ok) res += edge[i].cost;
        conn += ok;
        if (conn == n - 1) break;
    }
    if (conn == n - 1) printf("%lld\n", res);
    else printf("-1\n");
    return 0;
}
