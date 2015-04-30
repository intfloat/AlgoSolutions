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

int dp[25][25][25][65];
int r, g, b;
int m, p, arr[100];
vector<int> v;
int res;

int solve() {
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    for(int i=0; i<v.size(); i++) {
        for(int rr=0; rr<=r; rr++)
        for(int gg=0; gg<=g; gg++)
        for(int bb=0; bb<=b; bb++) {
            if(rr-v[i] >= 0) 
                dp[rr][gg][bb][i+1] += dp[rr-v[i]][gg][bb][i]%p;
            if(gg-v[i] >= 0)
                dp[rr][gg][bb][i+1] += dp[rr][gg-v[i]][bb][i]%p;
            if(bb-v[i] >= 0)
                dp[rr][gg][bb][i+1] += dp[rr][gg][bb-v[i]][i]%p;
            dp[rr][gg][bb][i+1] %= p;
        }       
    }
    return dp[r][g][b][v.size()]%p;
}

int fast_pow(int a, int b) {
    if(b == 0) return 1;
    if(b == 1) return a%p;
    int tmp = fast_pow(a, b/2);
    tmp = (tmp*tmp)%p;
    if(b%2 == 1) tmp = (tmp*a)%p;
    return tmp;
}

int main() {
    scanf("%d%d%d%d%d", &r, &b, &g, &m, &p);
    res = 0;
    int n = r + g + b;
    for(int i=0; i<m; i++) {
        map<int, int> m;        
        for(int j=1; j<=n; j++) {
            scanf("%d", arr+j);
            m[arr[j]] = j;
        }
        bool visited[100];      
        v.clear();
        memset(visited, false, sizeof(visited));
        for(int j=1; j<=n; j++) {
            if(visited[j] == false) {
                visited[j] = true;
                int cur = m[j];
                int counter = 1; 
                while(visited[cur]==false) {
                    visited[cur] = true;
                    cur = m[cur];
                    ++counter;
                }
                v.push_back(counter);
            }
        }
        res = (res + solve())%p;
    }   
    v.clear();
    // equal transform case
    for(int i=1; i<=n; i++) v.push_back(1);
    res = (res + solve())%p;
    // should be 6, get 4 instead   
    res = res * fast_pow(m+1, p-2);
    res = res%p;
    printf("%d", res);
    return 0;
}
