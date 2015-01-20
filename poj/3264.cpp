#include <vector>
#include <list>
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
using namespace std;

int height[50005];
int n, q;
int mx[50005][16], mn[50005][16];

// Initialize arrays
void rmq_init(){
    for(int i=0; i<n; i++){
        mx[i][0] = i;
        mn[i][0] = i;
    }
    
    for(int i=1; (1<<i)<=n; i++){
        for(int j=0; (j+(1<<i)-1)<n; j++){
            // Update minimal records
            if(height[mn[j][i-1]] < height[mn[j+(1<<(i-1))][i-1]])
                mn[j][i] = mn[j][i-1];
            else 
                mn[j][i] = mn[j+(1<<(i-1))][i-1];
            // Update maximal records
            if(height[mx[j][i-1]] > height[mx[j+(1<<(i-1))][i-1]])
                mx[j][i] = mx[j][i-1];
            else
                mx[j][i] = mx[j+(1<<(i-1))][i-1];
        }
    }
    return;
}

// Response q query
int query(int left, int right){
    int k = 0;
    int length = right-left+1;
    while((1<<(k+1)) < length)
        k++;    
    int mini = min(height[mn[left][k]], height[mn[right-(1<<k)+1][k]]);
    int maxi = max(height[mx[left][k]], height[mx[right-(1<<k)+1][k]]);
    //cout<<"maxi: "<<maxi<<" mini: "<<mini<<endl;
    return maxi-mini;
}

int main(){ 
    scanf("%d%d", &n,&q);
    for(int i=0; i<n; i++)
        scanf("%d", height+i);
    rmq_init();
    for(int i=0; i<q; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l-1, r-1));
    }
    //system("pause");
    return 0;
}
