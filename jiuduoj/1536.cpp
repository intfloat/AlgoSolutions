// two iterations of bfs
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
 
const int MAX_N = 1000005;
int n;
vector<int> g[MAX_N];
bool visited[MAX_N];
 
int main() {    
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i <= n; ++i) g[i].clear();
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v); g[v].push_back(u);
        }
        memset(visited, false, sizeof(visited));
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int last;
        while (!q.empty()) {
            int e = q.front(); q.pop();
            last = e;
            vector<int>::iterator it = g[e].begin();
            for (; it != g[e].end(); ++it) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    q.push(*it);
                }
            }
        }
         
        queue<pair<int, int> > qu;
        memset(visited, false, sizeof(visited));
        visited[last] = true;
        qu.push(make_pair(last, 0));
        int res = 0;
        while (!qu.empty()) {
            pair<int, int> cur = qu.front(); qu.pop();
            res = max(res, cur.second);
            vector<int>::iterator it = g[cur.first].begin();
            for (; it != g[cur.first].end(); ++it) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    qu.push(make_pair(*it, cur.second + 1));
                }
            }
        }
        printf("%d\n", (res + 1) / 2);
    }
    return 0;
}
 
/**************************************************************
    Problem: 1536
    User: BananaTree
    Language: C++
    Result: Accepted
    Time:3580 ms
    Memory:59440 kb
****************************************************************/
