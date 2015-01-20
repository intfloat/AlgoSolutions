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

const int MAX_N = 30005;
const int MAX_M = 250005;

int ptr = 0;
int head[MAX_N], pnt[MAX_M], next[MAX_M], wei[MAX_M];

void addedge(int x, int y, int w) {
    wei[ptr] = w; pnt[ptr] = y; next[ptr] = head[x]; head[x] = ptr++;   
}

int dis[MAX_N];
void spfa(int u) {
    stack<int> q;
    bool inq[MAX_N];
    memset(inq, false, sizeof(inq));
    q.push(u); inq[u] = true;
    while (!q.empty()) {
        int tp = q.top(); q.pop(); inq[tp] = false;     
        for (int i = head[tp]; i >= 0; i = next[i]) {           
            if (dis[tp] + wei[i] < dis[pnt[i]]) {
                dis[pnt[i]] = dis[tp] + wei[i];
                if (!inq[pnt[i]]) { inq[pnt[i]] = true; q.push(pnt[i]); }
            }
        }
    }
}

int main() {
    int n, m;   
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) { 
        dis[i] = INT_MAX / 2;
        head[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        addedge(a, b, c);
    }   
    dis[1] = 0;
    spfa(1);
    printf("%d\n", dis[n]);
    return 0;
}
