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

// Dynamic Programming problems
int main(){ 
    string str[105];
    int dp[105][105];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>str[i];
    for(int j=0; j<n; j++)
    for(int i=0; i<(2*n-1-2*j); i++)
        dp[j][i] = 1;
    int res = 1;
    
    // Even cases
    for(int i=1; i<n; i++){
        for(int j=0; j<(2*n-1-2*i); j++){
            if(str[i][j]=='#')
                continue;
            if(j%2 == 0){
                if(str[i-1][j]==str[i][j]
                    && str[i-1][j+1]==str[i][j]
                    && str[i-1][j+2]==str[i][j]){
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j+2])+1;
                    res = max(dp[i][j], res);
                }
            }
        }
    }
    
    // Odd cases
    for(int i=n-2; i>=0; i--)
    for(int j=0; j<(2*n-1-2*i); j++){
        if(str[i][j]=='#')
            continue;
        if(j%2 == 1){
            if(j-2 < 0)
                continue;
            if(j >= (2*n-1-2*(i+1)) )
                continue;
            if(str[i][j]==str[i+1][j-2]
                &&str[i][j]==str[i+1][j-1]
                &&str[i][j]==str[i+1][j]){
                    dp[i][j] = min(dp[i+1][j-2], dp[i+1][j])+1;
                    res = max(res, dp[i][j]);
            }
        }
    }
    
    cout<<res*res<<endl;
    system("pause");
    return 0;
}
