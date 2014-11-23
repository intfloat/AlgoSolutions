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
	int n, arr[105], res=0;
	int count[105];
	memset(count, 0, sizeof(count));
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		res += arr[i];
		if(i > 0)
			count[i] = count[i-1]+arr[i];
		else
			count[i] = arr[i];
	}
	
	int ans = 0;
	for(int i=0; i<n; i++)
	for(int j=i; j<n; j++){
		int delta = 0;
		if(i > 0)
			delta = (j-i+1)-2*(count[j]-count[i-1]);
		else
			delta = (j-i+1)-2*count[j];
		ans = max(ans, res+delta);
	}
		
	cout<<ans<<endl;
	
	//system("pause");
	return 0;
}
