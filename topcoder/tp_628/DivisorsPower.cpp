#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

using namespace std;

class DivisorsPower {
public:
	long long findArgument(long long);
	int cmp(long long num, int p, long long n) {		
		long long cur = 1;
		for (int i = 0; i < p; ++i) {
			cur = cur * num;
			if ((i == p-1) && (cur == n)) return 0;
			else if ((i < p-1) && (cur >= n)) return 1;
			else if (i < p-1 && cur < 0) return 1;
		}
		if (cur > n || cur < 0) return 1;
		else return -1;
	}

	int check(long long num) {
		int res = 0;		
		for (long long i = 1; i*i <= num; ++i) {
			if (num % i == 0) {
				if (i*i == num) res += 1;
				else res += 2;
			}
		}		
		return res;
	}
};

long long DivisorsPower::findArgument(long long n) {
	int left = 2;
	int right = 64;
	for (int i = left; i <= right; ++i) {
		long long a = 2;
		long long b = sqrt(n) + 1ll;
		while (a <= b) {
			long long mid = (a + b) / 2;
			int ret = cmp(mid, i, n);
			if (ret == 0) {
				if (check(mid) == i) return mid;
				else break;
			}
			else if (ret < 0) a = mid + 1;
			else b = mid - 1;
		}
	}
	return -1;
}


//Powered by [KawigiEdit] 2.0!