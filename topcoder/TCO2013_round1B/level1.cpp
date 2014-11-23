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

class EllysPairs {
public:
	int getDifference(vector <int>);
};

int EllysPairs::getDifference(vector <int> knowledge) {
	int maxi = 0;
	int mini = 1000000;
	int len = knowledge.size();
	sort(knowledge.begin(), knowledge.end());
	for(int i=0; i<len; i++){
		maxi = max(maxi, knowledge[i]+knowledge[len-1-i]);
		mini = min(mini, knowledge[i]+knowledge[len-1-i]);
	}
	return maxi-mini;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
