/**************************************************************
    Problem: 1059
    User: BananaTree
    Language: C++
    Result: Accepted
    Time:328 ms
    Memory:1412 kb
****************************************************************/
 
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
 
const int MAX_N = 405;
vector<int> g[MAX_N];
int match[MAX_N];
bool visited[MAX_N];
 
bool dfs(int pos) {
    visited[pos] = true;
    int len = g[pos].size();
    for (int i = 0; i < len; ++i) {
        int cur = g[pos][i];
        if (visited[cur]) continue;
        visited[cur] = true;
        if (match[cur] == -1 || dfs(match[cur])) {
            match[cur] = pos;
            return true;
        }
    }
    return false;
}
 
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < MAX_N; ++i)  {
            g[i].clear();
            match[i] = -1;
        }
        for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int color;
            scanf("%d", &color);
            if (1 == color) g[i].push_back(n + j); 
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            memset(visited, false, sizeof(visited));
            ok = dfs(i);
            if (!ok) { printf("No\n"); break; }
        }
        if (ok) printf("Yes\n");
    }
    return 0;
}
﻿