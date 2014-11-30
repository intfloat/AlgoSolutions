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

const int MAX_N = 1005;
const int MAX_M = MAX_N * MAX_N;
int head[MAX_N], next[MAX_M], pnt[MAX_M], dis[MAX_M], ptr;
int pathTo[MAX_N], ans[MAX_N];

void addedge(int u, int v, int w) {
    next[ptr] = head[u]; head[u] = ptr; pnt[ptr] = v; dis[ptr++] = w;
    next[ptr] = head[v]; head[v] = ptr; pnt[ptr] = u; dis[ptr++] = w;
}

int spfa() {
    FOR(i, MAX_N) ans[i] = INT_MAX / 2;
    ans[1] = 0; pathTo[1] = -1;
    bool inq[MAX_N];
    memset(inq, false, sizeof(inq));
    queue<int> q; q.push(1);
    inq[1] = true;
    while (!q.empty()) {
        int tp = q.front(); q.pop(); inq[tp] = false;
        // cout << tp << endl;
        for (int i = head[tp]; i != -1; i = next[i]) {
            // cout << i << " " << next[i] << endl;
            // assert(i != next[i]);
            int v = pnt[i];
            if (ans[v] > ans[tp] + dis[i]) {
                ans[v] = ans[tp] + dis[i];
                pathTo[v] = tp;
                if (!inq[v]) { q.push(v); inq[v] = true; }
            }
        }
    }
    return 0;
}

int main() {
    int N, M, from, to, w, res;
    while (cin >> N >> M) {
        ptr = 0; res = -1;
        FOR(i, MAX_N) head[i] = -1;
        FOR(i, M) {
            scanf("%d%d%d", &from, &to, &w);
            addedge(from, to, w);
        }
        spfa();
        vector<int> v;
        int s = N;
        while (s >= 0) { v.push_back(s); s = pathTo[s]; }
        int prev, pos;
        FOR(i, v.size() - 1) {
            from = v[i]; to = v[i + 1];
            for (int j = head[from]; j != -1; j = next[j]) {
                if (pnt[j] == to) {
                    prev = dis[j];
                    pos = j;
                    dis[j] = dis[j ^ 1] = INT_MAX / 2;
                    break;
                }
            }
            spfa();
            res = max(res, ans[N]);
            dis[pos] = dis[pos ^ 1] = prev;
        }
        printf("%d\n", res);
    }
    return 0;
}
