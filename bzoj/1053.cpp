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
#include <cassert>
using namespace std;

typedef long long ll;
ll N, res;
int maxf;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
	            31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

void dfs(int d, long long cur, int f) {
	if (cur > N) return;
	if (f > maxf) {
		maxf = f;
		res = cur;
	}
	else if (f == maxf && cur < res) res = cur;
	if (cur * prime[d] > N) return;
	ll t = 1;
	for (int i = 1; i < 60; ++i) {
		t *= prime[d];
		if (cur * t > N) break;
		dfs(d + 1, cur * t, f * (i + 1));
	}
	return;
}

int main() {	
	cin >> N;
	res = N;
	maxf = 0;
	dfs(0, 1ll, 1);
	cout << res << endl;
	return 0;
}
