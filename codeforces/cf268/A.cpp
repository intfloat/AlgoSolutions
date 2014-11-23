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

int main(){
	int n, t, p;
	set<int> s;
	cin >> n;
	cin >> p;
	for (int i = 0; i < p; ++i) {
		cin >> t;
		s.insert(t);
	}
	cin >> p;
	for (int i = 0; i < p; ++i) {
		cin >> t;
		s.insert(t);
	}
	if (s.size() == n) cout << "I become the guy." << endl;
	else cout << "Oh, my keyboard!" << endl;
	return 0;
}
