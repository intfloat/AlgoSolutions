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
#include<iomanip>

using namespace std;

class RandomOption {
public:
    int len;
    int key;
    bool check[20][20];
    double dp[1<<14][15];
    double getProbability(int, vector <int>, vector <int>);
    double dfs(int remain, int last, int t);
};

double RandomOption::getProbability(int keyCount, vector <int> badLane1, vector <int> badLane2) {
    double res=0;
    len=badLane1.size();
    key=keyCount;
    //initialize variables
    memset(check,true,sizeof(check));
    for(int i=0;i<len;i++){
        check[badLane1[i]][badLane2[i]]=false;
        check[badLane2[i]][badLane1[i]]=false;
    }
    for(int i=0;i<(1<<14);i++)
    for(int j=0;j<15;j++)
        dp[i][j]=-1;
    
    int begin=(1<<keyCount)-1;
    res=dfs(begin, keyCount, keyCount);
    return res;
}

double RandomOption::dfs(int remain, int last, int t){
    //boundary conditions
    if(remain==0 || t==0)
        return 1.0;
    if(dp[remain][last]!=-1)
        return dp[remain][last];
    
    double result=0;
    for(int i=0;i<key;i++){
        if( ((1<<i)&remain) && check[i][last]==true){
            result += (1.0/t)*dfs(remain&(~(1<<i)), i, t-1);
        }
    }
    dp[remain][last]=result;
    return result;
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
