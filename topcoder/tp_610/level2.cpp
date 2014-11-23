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
#include <stdlib.h>
#include <string.h>
#include <ctime>

using namespace std;

class AlbertoTheAviator {
public:
	int MaximumFlights(int, vector <int>, vector <int>);	
};

// use dynamic programming to solve this problem
int AlbertoTheAviator::MaximumFlights(int F, vector <int> duration, vector <int> refuel) {
	vector<pair<int, int> >	v;
	int dp[55][5005];
	memset(dp, 0, sizeof(dp));
	v.clear();
	int len = duration.size();
	for(int i=0; i<len; i++) v.push_back(make_pair(-refuel[i], duration[i]));	
	sort(v.begin(), v.end());
	int res = 0;
	// dp[i]][j] denotes: most mission with remaining j units fuel 
	// after checking v[i-1]
	for(int i=len-1; i>=0; i--){
		for(int j=F; j>=0; j--){
			int t = j-(v[i].first+v[i].second);
			if(t<0 || j<v[i].second) dp[i][j] = dp[i+1][j];
			else  dp[i][j] = max(dp[i+1][j], dp[i+1][t]+1);			
		}
	}
	res = dp[0][F];
	return res;
}


//Powered by [KawigiEdit] 2.0!