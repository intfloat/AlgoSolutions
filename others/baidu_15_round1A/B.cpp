#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
const int MAXN = 10005;
int val[MAXN];
int dp[MAXN][16], mn[MAXN][16];
int N;
void rmq_init(){  
    for(int i=0; i<N; i++)  dp[i][0] = mn[i][0] = val[i];
    for(int i=1; (1<<i)<=N; i++){  
        for(int j=0; (j+(1<<i)-1)<N; j++){              
            dp[j][i] = max(dp[j][i-1], dp[j+(1<<(i-1))][i-1]);  
            mn[j][i] = min(mn[j][i - 1], mn[j + (1 << (i - 1))][i - 1]);
        }  
    }  
    return;  
}
inline bool check(int left, int right){     
    int k = 0;  
    int length = right-left+1;  
    while((1<<(k+1)) < length) k++;    
    int mx = max(dp[left][k], dp[right-(1<<k)+1][k]);
    int mm = min(mn[left][k], mn[right - (1 << k) + 1][k]);
    if (mx - mm != right - left) return false;
    else return true;
}
int tag[MAXN];
void preprocess() {
    tag[0] = 0;
    map<int, int> mp;
    mp[val[0]] = 0;
    for (int i = 1; i < N; ++i) {
        if (mp.find(val[i]) == mp.end()) {
            mp[val[i]] = i;
            tag[i] = tag[i - 1];
        }
        else {
            tag[i] = max(mp[val[i]] + 1, tag[i - 1]);
            mp[val[i]] = i;
        }
    }
    return;
}
inline void solve() {
    int query, res, m;
    scanf("%d %d", &N, &query);
    FOR(i, N) scanf("%d", val + i);
    preprocess();
    rmq_init();
    FOR(i, query) {
        scanf("%d", &m);
        res = 0;
        for (int j = m - 1; j < N; ++j) {
            if (tag[j] <= j - m + 1 && check(j - m + 1, j)) ++res;
        }
        printf("%d\n", res);
    }
    return;
}
int main() {
    int T = 1;    
    FOR(tt, T) {
        printf("Case #%d:\n", tt + 1);
        solve();
    }
    return 0;
}
