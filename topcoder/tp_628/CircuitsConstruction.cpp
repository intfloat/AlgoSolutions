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
#include <cassert>

using namespace std;

class CircuitsConstruction {
public:
	int len;
	int pos;
	string c;
	int rec() {
		// assert(pos < len);
		if (c[pos] == 'A') {
			++pos;
			int t1 = rec();
			++pos;
			int t2 = rec();
			return t1 + t2;
		}
		else if (c[pos] == 'B') {
			++pos;
			int t1 = rec();
			++pos;
			int t2 = rec();
			return max(t1, t2);
		}		
		return 1;
	}
	int maximizeResistance(string, vector <int>);
};

int CircuitsConstruction::maximizeResistance(string circuit, vector <int> conductors) {
	len = circuit.size();
	c = circuit;
	if (len == 1) return conductors[0];
	pos = 0;
	int mx = rec();
	sort(conductors.begin(), conductors.end(), greater<int>());
	int res = 0;
	for (int i = 0; i < mx; ++i) {
		res += conductors[i];
	}
	return res;
}


//Powered by [KawigiEdit] 2.0!