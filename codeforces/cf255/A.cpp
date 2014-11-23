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

const int MAX_N = 100005;

int main(){		
	int arr[MAX_N], dp1[MAX_N], dp2[MAX_N];
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", arr+i);
	dp1[0] = 1;
    for(int i=1; i<n; i++) {
    	if (arr[i] > arr[i-1]) dp1[i] = dp1[i-1] + 1;
    	else dp1[i] = 1;
    }
    dp2[n-1] = 1;
    for(int i=n-2; i>=0; i--) {
    	if (arr[i] < arr[i+1]) dp2[i] = dp2[i+1] + 1;
    	else dp2[i] = 1;
    }

    int res = 1;
    for(int i=0; i<n; i++) {
    	if (i == 0) res = max(res, dp2[i+1]+1);
    	else if(i == n-1) res = max(res, dp1[i-1]+1);
    	else if(arr[i+1] >= arr[i-1]+2) res = max(res, dp1[i-1]+dp2[i+1]+1);
    	else res = max(res, 1 + max(dp1[i-1], dp2[i+1]));
    }
    printf("%d\n", res);
	return 0;
}
