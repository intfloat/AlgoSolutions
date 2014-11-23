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
	long long row, col, k;
	cin>>row>>col>>k;
	long long up = row + col - 2;
	if (k > up) {
		cout<<-1<<endl;
		return 0;
	}
	long long res = 1;
	long long t1 = max(0LL, k+1-row);
	long long t2 = min(k, col-1);
	for (int i=t1; i<=min(t1+10000, t2); ++i) 
		res = max(res, (col/(i+1)) * (row/(k-i+1)) );	
	for (int i=t2; i>=max(t2-10000, t1); --i)
		res = max(res, (row/(k-i+1)) * (col/(i+1)) );
	cout<<res<<endl;
	return 0;
}
