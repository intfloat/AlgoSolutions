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
	int cur, res;
	int n, arr[100005];
	cin>>n;
	//cin>>arr[0];
	res = 0;
	cur = 1;
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
	for(int i=1; i<n; i++){
		int counter = arr[i]-arr[i-1];
		while(counter>0 && cur>0){
			if(cur&1)
				res++;
			cur = cur>>1;
			counter--;
		}
		cur++;
	}
	int mx = arr[n-1];
	while(cur>1){
		if(cur&1)
			res++;
		cur = cur>>1;
		mx++;
	}
	cout<<mx-res<<endl;
	//system("pause");
	return 0;
}
