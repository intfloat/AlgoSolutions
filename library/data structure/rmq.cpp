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

const int MAXN = 50005;
int val[MAXN];
int dp[MAXN][20];
int N;

// Initialize arrays  
void rmq_init(){  
    for(int i=0; i<N; i++)  
        dp[i][0] = val[i];      
    for(int i=1; (1<<i)<=N; i++){  
        for(int j=0; (j+(1<<i)-1)<N; j++){  
            // Update minimal or maximal records  
            dp[j][i] = max(dp[j][i-1], dp[j+(1<<(i-1))][i-1]);  
        }  
    }  
    return;  
}  
  
// Response q query in range [left, right], inclusive
int query(int left, int right){ 
    if(left > right) return -1;
    int k = 0;  
    int length = right-left+1;  
    while((1<<(k+1)) < length) k++;
    // change max to min if you want to get minimal value    
    int mx = max(dp[left][k], dp[right-(1<<k)+1][k]);  
    return mx;
}

int main(){	
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>val[i];
    rmq_init();
    int left = 1;
    int right = N-1;
    cout<<query(left, right)<<endl;
	return 0;
}
