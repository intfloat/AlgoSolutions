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

class VacationTime {
public:
	int bestSchedule(int, int, vector <int>);
};

int VacationTime::bestSchedule(int N, int K, vector <int> workingDays) {
	int res = 1005;
	bool check[1005];
	memset(check, false, sizeof(check));
	int len = workingDays.size();
	for(int i=0; i<len; i++)
		check[workingDays[i]]=true;
	for(int i=1; i<=N-K+1; i++){
		int tmp = 0;
		for(int j=i; j<i+K; j++){
			if(check[j]==true)
				tmp++;
		}
		res = min(res, tmp);
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
