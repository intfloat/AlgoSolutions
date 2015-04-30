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

int n, m, K, e;
int g[25][25], cost[105][105];
int dp[105];
bool ok[25][105];
bool flag[25];
const int INF = INT_MAX/2;

int dijkstra() {
    int dis[25];
    int visited[25];
    for(int i=0; i<25; i++) {
        visited[i] = false;
        dis[i] = INF;
    }
    dis[1] = 0; 
    for(int i=0; i<m; i++) {
        int cur = INF;
        int index = -1;
        // find minimum
        for(int j=1; j<=m; j++) {           
            if(flag[j] && visited[j]==false && dis[j]<cur) {                
                cur = dis[j];
                index = j;
            }
        }
        if(index < 0) break; 
        // update
        visited[index] = true;
        for(int j=1; j<=m; j++)
            dis[j] = min(dis[j], dis[index] + g[index][j]);
    }
    return dis[m];
}

int main() {
    scanf("%d%d%d%d", &n, &m, &K, &e);
    for(int i=0; i<25; i++) {
        for(int j=0; j<25; j++) {
            g[i][j] = INF;  
        }
    }
    for(int i=0; i<105; i++) dp[i] = INF;
    memset(ok, true, sizeof(ok));
    int a, b, c;
    for(int i=0; i<e; i++) {
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
        g[b][a] = min(g[b][a], c); // undirected edge
    }
    int d, P;
    scanf("%d", &d);
    for(int i=0; i<d; i++) {
        scanf("%d%d%d", &P, &a, &b);
        for(int j=a; j<=b; j++) ok[P][j] = false;
    }
// precompute cost array
    for(int i=1; i<=n; i++) {
        for(int j=0; j<25; j++) flag[j] = ok[j][i];
        for(int j=i; j<=n; j++) {
            for(int kk=0; kk<25; kk++) {
                flag[kk] = flag[kk] && ok[kk][j];
            }
            cost[i][j] = dijkstra();
            // cout<<i<<" "<<j<<" "<<cost[i][j]<<endl;
        }
    }
    // dynamic programming to solve the problem
    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        for(int j=i-1; j>=0; j--) {
            if (cost[j+1][i] >= INF) continue;
            dp[i] = min(dp[i], dp[j] + cost[j+1][i]*(i-j) + K);
        }
    }
    printf("%d\n", dp[n]-K);
    return 0;
}
