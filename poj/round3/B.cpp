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

int main(){
    int n, m;
    int arr[100005];
    int tmp[105];
    while(cin>>n>>m){
        for(int i=0; i<n; i++) scanf("%d", arr+i);
        int l, r, p;
        for(int i=0; i<m; i++){
            scanf("%d%d%d", &l, &r, &p);
            l--; r--;
            int len = (r-l+1);
            if(len >= p){
                printf("0\n"); continue;
            }
            int mn = 1000;
            tmp[0] = (arr[l]%p);
            for(int j=1; j<len; j++){
                tmp[j] = (tmp[j-1]+arr[j+l])%p;
            }
            for(int j=0; j<len; j++){
                for(int k=j; k<len; k++){
                    mn = min(mn, (tmp[k]-tmp[j]+arr[l+j]+p)%p);
                    if(mn == 0) break;
                }
            }
            printf("%d\n", mn);
        }
    }
	return 0;
}
