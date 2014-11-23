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


int n, k, w, c[100005];
int dp[100005][17];
string str;
void rmq_init(){
    for(int i=0; i<n; i++) dp[i][0] = c[i];
    for(int i=1; (1<<i)*k<=n; i++){
        for(int j=0; (j+(1<<i)*k-1)<n; j++){
            //if(dp[j][i-1] > dp[j+(1<<(i-1))*k][i-1])
            dp[j][i] = dp[j][i-1]+dp[j+(1<<(i-1))*k][i-1];
            //else dp[j][i] = dp[j+(1<<(i-1))*k][i-1];
        }
    }
    return;
}

int query(int left, int right){
    if(left > right) return -1;
    int bi = 0;
    int len = (right-left+1)/k;
    int ptr = 0;
    int res = 0;
    while((1<<bi)<=len){
        if(((1<<bi)&len) != 0){
            res += dp[ptr*k+left][bi];
            ptr += (1<<bi);
        }
        ++bi;
    }
    //while((1<<(bi+1)) < len) ++bi;
    //int res = max(dp[left][bi], dp[right-(1<<bi)*k+1][bi]);
    return res;
}

int main(){		
    scanf("%d%d%d", &n, &k, &w);
    cin>>str;
    memset(c, 0, sizeof(c));
    for(int i=0; i<=n-k; i++){
        for(int j=i; j<i+k-1; j++) c[i] += (str[j]=='1');
        c[i] += (str[i+k-1]=='0');
    }
    rmq_init();
    for(int i=0; i<w; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        --l; --r;
        printf("%d\n", query(l, r));
    }
	return 0;
}
