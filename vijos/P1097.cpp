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

// Know about the use of heap
// It will be a maximal heap in default
// And greater<int>() will make it a minimal heap
int main(){	
	int n, tmp;
	vector<int> v;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>tmp;
		v.push_back(tmp);
	}
	int res = 0;
	int mn1, mn2;
	make_heap(v.begin(), v.end(), greater<int>());
	for(int i=0; i<n-1; i++){
		mn1 = v.front();
		pop_heap(v.begin(), v.end(), greater<int>());
		v.pop_back();
		mn2 = v.front();
		pop_heap(v.begin(), v.end(), greater<int>());
		v.pop_back();
		res += mn1+mn2;
		v.push_back(mn1+mn2);
		push_heap(v.begin(), v.end(), greater<int>());
	}
	cout<<res<<endl;
	system("pause");
	return 0;
}
