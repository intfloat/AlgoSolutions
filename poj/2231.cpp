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

int main() {
	int n, arr[10005];
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	long long res = 0;
	sort(arr, arr + n);
	for (int i = 1; i < n; ++i) res += 2ll * i * (n - i) * (long long)(arr[i] - arr[i - 1]);
	cout << res << endl;
	return 0;
}
