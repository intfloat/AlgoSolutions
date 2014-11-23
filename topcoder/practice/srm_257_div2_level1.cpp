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

class HingedDoor {
public:
	int numSwings(int, int);
};

int HingedDoor::numSwings(int initialAngle, int reduction) {
	int res = 0;
	double angle = initialAngle;
	while(angle > 5.0){
		angle = angle/reduction;
		res++;
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
