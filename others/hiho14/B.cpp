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
typedef long long ll;
typedef pair<int, int> point;
const int MAX_N = 100005;
int head[MAX_N], pnt[MAX_N], nt[MAX_N], ptr = 0, dis[MAX_N];
inline void addedge(int from, int to) {
    pnt[ptr] = to; nt[ptr] = head[from]; head[from] = ptr++;
}
void dfs(int root) {
    dis[root] = 0;
    for (int i = head[root]; i != -1; i = nt[i]) {
        int to = pnt[i];
        dfs(to);
        dis[root] = max(dis[root], dis[to] + 1);
    }
}
int res = 0;
void solve(int root, int pv, int dep) {
    if (pv > 0) res = max(res, pv + dis[root] + 1);
    vector<point> arr;
    for (int i = head[root]; i != -1; i = nt[i]) {
        int to = pnt[i];
        arr.push_back(make_pair(dis[to] + dep + 1, to));
    }
    sort(arr.begin(), arr.end(), greater<point>());
    if (arr.size() > 2) arr.resize(2);
    while (arr.size() < 2) arr.push_back(make_pair(-1, -1));
    for (int i = head[root]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (arr[0].first <= pv) solve(to, pv, dep + 1);
        else if (arr[0].second != to) solve(to, arr[0].first, dep + 1);
        else solve(to, max(pv, arr[1].first), dep + 1);
    }
}
int main() {
    int N, from, to;
    scanf("%d", &N);
    memset(head, -1, sizeof head);
    FOR(i, N - 1) {
        scanf("%d %d", &from, &to);
        addedge(from, to);
    }
    dfs(1);
    res = dis[1];
    solve(1, -1, 0);
    printf("%d\n", res);
    return 0;
}
