/**************************************************************
    Problem: 1051
    User: BananaTree
    Language: C++
    Result: Accepted
    Time:128 ms
    Memory:2776 kb
****************************************************************/
 
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
 
using namespace std;
 
const int MAX_N = 10005;
vector<int> g[MAX_N], rg[MAX_N], tp;
int N, M, scc[MAX_N], comp, cnt[MAX_N];
bool visited[MAX_N];
 
void dfs1(int pos) {
    visited[pos] = true;
    vector<int>::iterator it;
    for (it = rg[pos].begin(); it!=rg[pos].end(); ++it) {
        if (!visited[*it]) dfs1(*it);
    }
    tp.push_back(pos);
    return;
}
 
void dfs2(int pos) {
    visited[pos] = true;
    int len = g[pos].size();
    for (int i = 0; i < len; ++i) {
        if (!visited[g[pos][i]]) dfs2(g[pos][i]);
    }
    scc[pos] = comp;
    return;
}
 
int main() {
    int x, y;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        rg[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    tp.clear();
    // topological sort
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) dfs1(i);
    }
    reverse(tp.begin(), tp.end());
     
    // find strong connected components
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < MAX_N; ++i) scc[i] = -1;
    comp = 0;
    int len = tp.size();
    for (int i = 0; i < len; ++i) {      
        if (!visited[tp[i]]) {
            dfs2(tp[i]);
            ++comp; 
        }
    }
 
    vector<int> res;  
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i <= N; ++i) {               
        len = g[i].size();
        for (int j = 0; j < len; ++j) {
            if (scc[i] == scc[g[i][j]]) continue;
            ++cnt[scc[i]];
        }
    }
    for (int i = 0; i < comp; ++i) {     
        if (cnt[i] == 0) res.push_back(i);
    }
 
    // more than one isolated SCC
    if (res.size() > 1) printf("0\n");
    else {
        int num = 0;
        for (int i = 0; i <= N; ++i) {           
            num += (scc[i] == res[0]);
        }
        printf("%d\n", num);
    }
    return 0;
}