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

int main() {
	int L, N, M, pos[50005];
	cin >> L >> N >> M;
	pos[0] = 0; pos[N + 1] = L;
	for (int i = 1; i <= N; ++i) cin >> pos[i];
	int left = 0, right = L;
	sort(pos, pos + N + 2);
	while (left < right) {
		int mid = (left + right) / 2;
		if (mid == left) mid = right;
		int cnt = 0, ptr = 1, cur = 0;
		while (ptr <= N + 1) {
			if (pos[ptr] - pos[cur] < mid) { ++cnt; ++ptr; }
			else { cur = ptr; ++ptr; }
		}
		if (cnt > M) right = mid - 1;
		else left = mid;
	}
	cout << left << endl;
	return 0;
}
