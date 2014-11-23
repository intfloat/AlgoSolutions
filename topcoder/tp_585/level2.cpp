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

class LISNumber {
public:
	int count(vector <int>, int);
};

// 把数量限制忘了，擦。。。 
int LISNumber::count(vector <int> cardsnum, int K) {
	int total = 0, len = cardsnum.size();
	int n = len-1;
	for(int i=0; i<len; i++)
		total += cardsnum[i];
	long long dp[1300][40][1300];
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<=n; i++)
		dp[0][i][1] = 1;
	for(int pos=1; pos<total; pos++){
		for(int i=0; i<=n; i++){
			for(int kk=1; kk<=pos; kk++){
				for(int j=0; j<i; j++)
					dp[pos][i][kk] = dp[pos][i][kk]+dp[pos-1][j][kk];
				for(int j=i; j<=n; j++)
					dp[pos][i][kk] = dp[pos][i][kk]+dp[pos-1][j][kk-1];
			}
		}
	}
	long long res = 0;
	for(int i=0; i<=n; i++)
		res = res+dp[n][i][K];
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
