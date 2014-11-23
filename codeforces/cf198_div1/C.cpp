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
#define MOD 1000000007 
using namespace std;

long long arr[2005][2005];     
 
long long howMany(int N, int K) {  
    long long res = 0;  
    for(long long i=0; i<=N; i++){  
        for(long long j=0; j<=K && j<=i; j++){  
            if(i==0 && j==0)    arr[i][j] = 1;  
            else if(j==0) arr[i][j] = (i*arr[i-1][0])%MOD;  
            else if(j==1) arr[i][j] = ((i-1)*arr[i-1][0])%MOD;  
            else if(i == 0) arr[i][j] = 0;  
            else{  
                arr[i][j] = ((j-1)*(arr[i-2][j-2]+arr[i-1][j-1]))%MOD + ((i-j)*(arr[i-2][j-1]+arr[i-1][j]))%MOD;  
                arr[i][j] %= MOD;  
            }  
        }  
    }  
    res = arr[N][K];  
    return res;  
}  

int main(){		
	int n;
	int arr[100005];
	bool check[100005];
	int counter = 0;
	memset(check, false, sizeof(check));
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		if(arr[i] == -1)
			counter++;
		else
			check[arr[i]] = true;
	}
	int kk = 0;
	for(int i=1; i<=n; i++){
		if(check[i]==false && arr[i]==-1)
			kk++;
	}
	cout<<howMany(counter, kk)<<endl;
	//system("pause");
	return 0;
}
