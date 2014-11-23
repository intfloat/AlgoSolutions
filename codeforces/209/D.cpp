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
int n;
int* arr;
int **arrgcd, **arrmin;
vector<int> res;

// Initialize arrays  
void rmq_init(){  
    for(int i=0; i<n; i++){  
        arrgcd[i][0] = arr[i];  
        arrmin[i][0] = arr[i];  
    }  
      
    for(int i=1; (1<<i)<=n; i++){  
        for(int j=0; (j+(1<<i)-1)<n; j++){  
            // Update minimal records  
            if(arrmin[j][i-1] < arrmin[j+(1<<(i-1))][i-1])  
                arrmin[j][i] = arrmin[j][i-1];  
            else   
                arrmin[j][i] = arrmin[j+(1<<(i-1))][i-1];  
            // Update maximal records  
            arrgcd[j][i] = __gcd(arrgcd[j][i-1], arrgcd[j+(1<<(i-1))][i-1]);    
            
            //if(height[arrgcd[j][i-1]] > height[arrgcd[j+(1<<(i-1))][i-1]])  
             //   arrgcd[j][i] = arrgcd[j][i-1];  
            //else  
            //    arrgcd[j][i] = arrgcd[j+(1<<(i-1))][i-1];  
        }  
    }  
    return;  
}  
  
// Response q query  
bool query(int left, int right){  
    int k = 0;  
    int length = right-left+1;  
    while((1<<(k+1)) < length)  
        k++;      
    int mini = min(arrmin[left][k], arrmin[right-(1<<k)+1][k]);  
    int maxi = __gcd(arrgcd[left][k], arrgcd[right-(1<<k)+1][k]);  
    if(mini == maxi) return true;
    return false;  
}

bool check(int len){
    res.clear();
    for(int i=0; i<n; i++){
        if(i+len-1 > n-1) break;
        if(query(i, i+len-1) == true){
            res.push_back(i);
        }
    }
    return (res.size()!=0);
}

int main(){	
    scanf("%d", &n);
    arr = new int[n+55];
    arrgcd = new int*[n+55];
    arrmin = new int*[n+55];
    for(int i=0; i<(n+55); i++){
        arrgcd[i] = new int[20];
        arrmin[i] = new int[20];
    }
    for(int i=0; i<n; i++)
      scanf("%d", arr+i);
    rmq_init();
    int left = 1;
    int right = n;
    while(left+1 < right){
        int mid = (left+right)/2;
        bool ok = check(mid);
        if(ok == true) left=mid;
        else right = mid-1;
    }
    bool ok = check(right);
    if(ok == false) check(left);
    else left = right;
    cout<<res.size()<<" "<<left-1<<endl;
    for(int i=0; i<res.size(); i++)
        cout<<res[i]+1<<" ";
    cout<<endl;
	return 0;
}
