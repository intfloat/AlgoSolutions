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
    int a, b, n;
    int arr[10005];
    while(cin>>n>>a>>b){
        for(int i=0; i<n; i++)
            cin>>arr[i];
        sort(arr, arr+n);
        int res = 0;
        bool all = true;
        for(int i=0; i<n; i++){
            if(a==0 && b==0){
                res = i;
                all = false;
                break;
            }
            if(arr[i]<=3 && a>0){
                a--; continue;                
            }
            if(arr[i]<=4 && b>0){
                b--; continue;
            }
            if(arr[i]>(a+2*b+2)){
               res = i;
               all = false;
               break;
            }
            int tmp = (arr[i]-2)/2;
            if(tmp <= b){
                b -= tmp;
                if(arr[i]%2 == 1){
                    if(a>0) a--;
                    else b--;
                }
                continue;
            }
            if(b>0){
                arr[i] -= 2*b+2;
                b = 0;
                a -= arr[i];
                continue;
            }
            if(b==0){
                a -= (arr[i]-2);
                continue;
            }

        }
        if(all == true) cout<<n<<endl;
        else cout<<res<<endl;
    }
	return 0;
}
