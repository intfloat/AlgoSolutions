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
	int n, t;
	int arr[MAX_N];
	long long res[MAX_N];
	memset(arr, 0, sizeof(arr));
	memset(res, 0, sizeof(res));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		++arr[t];
	}
	res[1] = arr[1] * 1;
	res[2] = max(res[1], arr[2] * 2ll);
	for (int i = 3; i < MAX_N; ++i) {
		res[i] = max((long long)i * arr[i] + res[i - 2], (long long)(i - 1) * arr[i - 1] + res[i - 3]);
	}
	cout << res[MAX_N - 1] << endl;
	return 0;
}
