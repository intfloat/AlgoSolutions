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

const int MAX_N = 10005;
int main() {
	int n, m, L, ptr = 0;
	int arr[MAX_N], dp[MAX_N], lis[MAX_N];
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = n - 1; i >= 0; --i) {
		int left = 0, right = ptr - 1;
		if (right < left || dp[right] > arr[i]) {
			dp[ptr++] = arr[i];
			lis[i] = ptr;			
			continue;
		}
		while (left < right) {
			int mid = (left + right) / 2;
			if (dp[mid] > arr[i]) left = mid + 1;
			else if (dp[mid] < arr[i]) right = mid;
			else { left = mid; break; }
		}
		lis[i] = left + 1;
		dp[left] = arr[i];
	}
	// for (int i = 0; i < n; ++i) cout << i << " " << lis[i] << endl;

	cin >> m;
	while (m--) {
		cin >> L;
		vector<int> res;
		if (L > ptr) { cout << "Impossible" << endl; continue; }
		int prev = INT_MIN;
		for (int i = 0; i < n; ++i) {
			if (lis[i] >= L && arr[i] > prev && L > 0) { res.push_back(arr[i]); --L; prev = arr[i]; }
		}
		cout << res[0];
		for (int i = 1; i < res.size(); ++i) cout << " " << res[i];
		cout << endl;
	}
	return 0;
}
