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

int m, k, book[505];
// use greedy strategy to check
bool check(int cur) {
	int num = 0;
	int c = 1;
	for(int i=0; i<m; i++) {
		if(num+book[i] > cur) {
			++c;
			num = book[i];
		}
		else num += book[i];
		if (c > k) return false;
	}
	return true;
}

int main() {
	int n;
	cin>>n;
	while(n--) {
		cin>>m>>k;
		int left = 0;
		int right = 0;
		for(int i=0; i<m; i++) {
			cin>>book[i];
			right += book[i];
			left = max(book[i], left);
		}
		// binary search
		while(left < right) {
			int mid = (left + right)/2;
			if(check(mid)) right = mid;
			else left = mid + 1;
		}
		cout<<left<<endl;
	}
	return 0;
}
