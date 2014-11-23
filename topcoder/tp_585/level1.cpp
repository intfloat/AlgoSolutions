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

class TrafficCongestion {
public:
	int theMinCars(int);
};

int TrafficCongestion::theMinCars(int treeHeight) {
	const long long MOD = 1000000007;
	if(treeHeight==0 || treeHeight==1)
		return 1;
	long long res = 0;
	long long pre = 2, prepre=1;
	for(int i=2; i<=treeHeight; i++){
		res = (1+2*prepre)%MOD;
		prepre = pre;
		pre = (res+pre)%MOD;
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
