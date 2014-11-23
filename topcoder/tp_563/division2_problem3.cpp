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
#include<string.h>

using namespace std;

class SpellCardsEasy {
public:
	int dp[55][55];
	int len;
	vector<int> lev,dam;
	int maxDamage(vector <int>, vector <int>);
	int solve(int pos, int owed);
};

int SpellCardsEasy::maxDamage(vector <int> level, vector <int> damage) {	
	len=level.size();
	lev=level; dam=damage;
	memset(dp,-1,sizeof(dp));
	return solve(0,0);
}

//solution to it is simple and excellent
int SpellCardsEasy::solve(int pos, int owed){
	if(dp[pos][owed] >= 0)
		return dp[pos][owed];
	if(owed == (len-pos)){
		dp[pos][owed]=0;		
	}
	else{
		dp[pos][owed]=max(dp[pos][owed], solve(pos+1, max(0,owed-1)));
		if((owed+lev[pos]) <= (len-pos))
			dp[pos][owed]=max(dp[pos][owed], dam[pos]+solve(pos+1, owed+lev[pos]-1));
	}
	return dp[pos][owed];
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
