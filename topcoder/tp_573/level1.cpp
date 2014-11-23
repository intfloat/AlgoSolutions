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

class SkiResortsEasy {
public:
	int minCost(vector <int>);
};

int SkiResortsEasy::minCost(vector <int> altitude) {
	int len = altitude.size();
	int res = 0;
	for(int i=1; i<len; i++){
		res += max(altitude[i]-altitude[i-1], 0);
		altitude[i] = min(altitude[i], altitude[i-1]);
	}
	return res;
}


<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

