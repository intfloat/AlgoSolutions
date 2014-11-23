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
	int n, k;
	cin >> n >> k;
	int res = (n * 6 - 1) * k;
	cout << res << endl;
	for (int i = 1; i <= n; ++i) {
		int t = (i - 1) * 6 + 1;
		cout << t * k << " " << (t + 1) * k << " " << (t + 2) * k << " " << (t + 4) * k << endl;
	}
	return 0;
}
