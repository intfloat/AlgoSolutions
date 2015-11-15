#include <string.h>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int dp[100];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1; dp[1] = 1;
        for(int i=2; i<=n; i++){
            for(int j=0; j<i; j++)
                dp[i] += dp[j]*dp[i-j-1];
        }
        
        return dp[n];
    }
};
