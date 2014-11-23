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


const int MAX_N = 300005;
int main(){
	long long res = 0;
	long long arr[MAX_N];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	if (1 == n) {
		cout << arr[0] << endl;
		return 0;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i) {
		if (0 == i) res += 2 * arr[i];
		else if (n - 1 == i) res += (i + 1) * arr[i];
		else res += (i + 2) * arr[i];
	}
	cout << res << endl;
	return 0;
}

