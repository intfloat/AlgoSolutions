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

const int MAX_N = 50005;
int p[MAX_N], relation[MAX_N];

int _find(int i) {
    if (p[i] == i) return i;
    int t = _find(p[i]);
    relation[i] = (relation[i] + relation[p[i]]) % 3;
    p[i] = t;
    return p[i];
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    memset(relation, 0, sizeof(relation));
    FOR(i, MAX_N) p[i] = i;
    int res = 0;
    FOR(i, K) {
        int d, x, y;
        scanf("%d %d %d", &d, &x, &y);
        --d;
        if (x > N || y > N) { ++res; continue; }
        if (x == y && d == 1) { ++res; continue; }
        int rx = _find(x), ry = _find(y);
        if (rx == ry && (relation[x] - relation[y] + 3) % 3 != d) ++res;
        else {
            p[rx] = p[ry];
            relation[rx] = (-relation[x] + d + relation[y] + 3) % 3;
        }
    }
    printf("%d\n", res);
    return 0;
}
