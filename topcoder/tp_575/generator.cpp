#include <vector>
#include <list>
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
#define John 1
#define Brus 2
using namespace std;
int dp[1005];

bool prime(int n){
    for(int i=2; i<n; i++){
        if(n%i == 0)
            return false;           
    }
    return true;
}

int main(){
    freopen("out.txt", "w", stdout);
    memset(dp, 0, sizeof(dp));
    dp[1] = Brus;
    dp[2] = Brus;
    dp[5] = Brus;
    dp[3] = Brus;
    for(int i=2; i<=100; i++){
        if(dp[i] == 0){
            if(prime(i) == true)
                dp[i] = Brus;
            for(int j=2; j*j<=i; j++){
                if(i%j == 0){
                    if(dp[i-j]==Brus || dp[i-i/j]==Brus){
                        dp[i] = John;
                        break;
                    }                   
                }
            }
            if(dp[i] == 0)
                dp[i] = Brus;
        }
        cout<<i<<": ";
        if(dp[i] == Brus)
            cout<<"Brus"<<endl;
        else
            cout<<"John"<<endl;
    }
}
