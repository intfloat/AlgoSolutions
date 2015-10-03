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
int N, D;
pair<int, int> cow[50005];
int val[50005];
int valmax[50005][20];
int pos[50005];

// Initialize arrays  
void rmq_init(){  
    for(int i=0; i<N; i++){  
        valmax[i][0] = val[i];  
    }  
    for(int i=1; (1<<i)<=N; i++){  
        for(int j=0; (j+(1<<i)-1)<N; j++){  
            // Update minimal records  
            if(valmax[j][i-1] > valmax[j+(1<<(i-1))][i-1])  
                valmax[j][i] = valmax[j][i-1];  
            else   
                valmax[j][i] = valmax[j+(1<<(i-1))][i-1];  
        }  
    }  
    return;  
}  
  
// Response q query  
int query(int left, int right){ 
    if(left > right) return -1;
    int k = 0;  
    int length = right-left+1;  
    while((1<<(k+1)) < length)  
        k++;      
    int mx = max(valmax[left][k], valmax[right-(1<<k)+1][k]);  
    return mx;
}

int main(){ 
    freopen("crowded.in", "r", stdin);
    freopen("crowded.out", "w", stdout);
    scanf("%d%d", &N, &D);
    for(int i=0; i<N; i++){
        scanf("%d%d", &cow[i].first, &cow[i].second);
    }
    sort(cow, cow+N);
    for(int i=0; i<N; i++){
        val[i] = cow[i].second;
        pos[i] = cow[i].first;
    }
    rmq_init();
    int res = 0;
    for(int i=0; i<N; i++){
        int l = lower_bound(pos, pos+N, pos[i]-D)-pos;
        int r = i;
        int mx = query(l, r);
        if(mx >= 2*val[i]){
            l = i; 
            r = lower_bound(pos, pos+N, pos[i]+D)-pos;
            if(r == N)
                r = N-1;
            while(pos[r]>pos[i]+D)
                r--;
            mx = query(l, r);
            if(mx >= 2*val[i])
                res++;
        }
    }
    cout<<res<<endl;
    return 0;
}
