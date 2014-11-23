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

const int SIZE = 200005;

int main(){		
	int n, k;
	long long arr[SIZE], sum[SIZE];
	pair<long long, long long> record[SIZE];
	memset(sum, 0, sizeof(sum));
	memset(arr, 0, sizeof(arr));
	scanf("%d%d", &n, &k);
	for(int i=0; i<=n; i++)
		record[i] = make_pair(0, 0);
	for(int i=1; i<=n; i++)
		cin>>arr[i];
		
	long long tmp = 0;
	for(int i=1; i<=n; i++){
		if(i<k)
			tmp += arr[i];
		else{						
			tmp += arr[i]-arr[i-k];
			sum[i-k+1] = tmp;
		}
	}
	
	pair<long long, long long> mini = make_pair(-1, -1);
	for(int i=n; i>=1; i--){
		if(sum[i]>=mini.first){
			record[i].first = sum[i];
			record[i].second = i;
			mini = record[i];
		}
		else
			record[i] = mini;
	}
	
	long long maxi = -1;
	pair<long long, long long> res;
	//for(int i=1; i<=n; i++)
	//	cout<<i<<" "<<sum[i]<<endl;
		
	for(int i=1; i<=n; i++){
		//cout<<i<<" "<<sum[i]<<endl;
		if(n-i+1 < 2*k)
			break;
		long long t = sum[i]+record[i+k].first;
		if(t > maxi){
			maxi = t;
			res = make_pair(i, record[i+k].second);
		}
	}
	cout<<res.first<<" "<<res.second<<endl;
	//system("pause");
	return 0;
}
