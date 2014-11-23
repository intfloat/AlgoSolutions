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

/*
1: no
2: no
3: no
4: yes 1 * 2 * 3 * 4 = 24
5: 1, 2, 3, 4, 5 : 4 * 5 + (3 - 1) + 2
6: 1, 2, 3, 4, 5, 6 : 4 * 6 + (5 - 2 - 3) * 1
>=6: yes
*/
int main(){
	int n;
	cin >> n;
	if (n <= 3) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	if (n == 4) {
		cout << "1 * 2 = 2" << endl;
		cout << "2 * 3 = 6" << endl;
		cout << "6 * 4 = 24" << endl;
		return 0;
	}
	if (n == 5) {
		cout << "4 * 5 = 20" << endl;
		cout << "3 - 1 = 2" << endl;
		cout << "2 + 2 = 4" << endl;
		cout << "20 + 4 = 24" << endl;
		return 0;
	}
	cout << "4 * 6 = 24" << endl;
	cout << "5 - 2 = 3" << endl;
	cout << "3 - 3 = 0" << endl;
	cout << "0 * 1 = 0" << endl;
	for (int i = 7; i <= n; ++i) cout << "0 * " << i << " = 0" << endl;
	cout << "24 + 0 = 24" << endl;
	return 0;
}
