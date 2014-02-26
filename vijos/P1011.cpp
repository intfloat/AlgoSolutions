#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <string.h>
#include <stdlib.h>
using namespace std;
int row, col, arr[505][505];
int dp[505][505];
int dir_r[] = {1, -1, 0, 0};
int dir_c[] = {0, 0, -1, 1};

int solve(int r, int c){
	if(dp[r][c] <= 0){
		for(int i=0; i<4; i++){
			int cur_r = r+dir_r[i];
			int cur_c = c+dir_c[i];
			if(cur_r<0 || cur_r>=row
				|| cur_c<0 || cur_c>=col)
				continue;
			if(arr[cur_r][cur_c] < arr[r][c])
				dp[r][c] = max(dp[r][c], solve(cur_r, cur_c)+1);
		}
	}
	return dp[r][c];
}

// dynamic programming and search strategy, no pressure~
int main(){		
	cin>>row>>col;
	for(int i=0; i<row; i++)
	for(int j=0; j<col; j++)
		cin>>arr[i][j];
	memset(dp, 0, sizeof(dp));
	int res = 0;
	for(int i=0; i<row; i++)
	for(int j=0; j<col; j++)
		res = max(res, solve(i, j));
	cout<<res+1<<endl;
	//system("pause");
	return 0;
}
