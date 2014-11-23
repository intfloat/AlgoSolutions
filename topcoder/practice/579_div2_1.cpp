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

class PrimalUnlicensedCreatures {
public:
	int maxWins(int, vector <int>);
};

int PrimalUnlicensedCreatures::maxWins(int initialLevel, vector <int> grezPower) {
	int res = 0;
	int len = grezPower.size();
	sort(grezPower.begin(), grezPower.end());
	int power = initialLevel;
	for(int i=0; i<len; i++){
		if(power > grezPower[i]){
			res++;
			power += grezPower[i]/2;
		}
		else
			break;
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
