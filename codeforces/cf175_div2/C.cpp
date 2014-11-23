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
	int n;
	int arr[300005];
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
	sort(arr, arr+n);
	long long res = 0;
	for(int i=0; i<n; i++)
		res += abs(i+1-arr[i]);
	cout<<res<<endl;
	system("pause");
	return 0;
}
