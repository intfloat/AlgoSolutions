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
	long long n, k;
	long long a[200005];
	cin>>n>>k;
	//int nn=n;
	long long pre = 0;
	long long counter = 0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		long long cur = pre-a[i]*(i-counter-1)*(n-i);		
		if(cur < k){
			counter++;
			cout<<i<<endl;
		}
		else{
			pre += a[i]*(i-counter-1);
		}
	}
	//system("pause");
	return 0;
}
