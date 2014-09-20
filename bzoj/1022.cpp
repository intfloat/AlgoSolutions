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
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, num;
		int res = 0;
		int cnt = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &num);
			res = res ^ num;
			cnt += (num > 1);
		}
		if (cnt == 0 && res % 2) printf("Brother\n");
		else if (cnt == 0 && res % 2 == 0) printf("John\n");
		else if (res == 0) printf("Brother\n");
		else printf("John\n");
	}
	return 0;
}
