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

int getR(int i, int j){
    bool flag[3];
    memset(flag, false, sizeof(flag));
    flag[i] = true;
    flag[j] = true;
    for(int k=0; k<3; k++){
        if(flag[k]==false) return k;
    }
    return 0;
}

int main(){
    int cost[3][3], n;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>cost[i][j];
        }
    }
    cin>>n;
    long long dp[3][3][45];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==j) continue;
            int r = getR(i, j);
            dp[i][j][1] = min(cost[i][j], cost[i][r]+cost[r][j]);
        }
    }
    for(int k=2; k<=n; k++){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(i==j) continue;
                int r = getR(i, j);
                dp[i][j][k] = dp[i][r][k-1]+cost[i][j]
                    +min(dp[r][j][k-1], dp[r][i][k-1]+dp[i][j][k-1]);
                long long tmp = dp[i][j][k-1]+cost[i][r]+cost[r][j]+dp[i][j][k-1]
                    +min(dp[j][i][k-1], dp[j][r][k-1]+dp[r][i][k-1]);
                dp[i][j][k] = min(dp[i][j][k], tmp);
            }
        }
    }
    cout<<dp[0][2][n]<<endl;
	return 0;
}
