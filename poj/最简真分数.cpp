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
	int n, arr[605];
	while(cin>>n && n){
		int res = 0;
		for(int i=0; i<n; i++)
			cin>>arr[i];
		for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++){
			if(__gcd(arr[i], arr[j])==1)
				res++;
		}
		cout<<res<<endl;
	}
	system("pause");
	return 0;
}
