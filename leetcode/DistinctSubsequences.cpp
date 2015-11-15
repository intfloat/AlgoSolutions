#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class Solution {
public:
    // use dynamic programming to solve this problem
    int numDistinct(string S, string T) {
        int len1 = S.size();
        int len2 = T.size();
        if(len1 < len2) return 0;
        int** dp = new int*[len1+1];
        for(int i=0; i<len1+1; i++)
            dp[i] = new int[len2+1];        
        for(int i=0; i<len1+1; i++){
            for(int j=0; j<len2+1; j++){
                dp[i][j] = 0;
            }
            dp[i][0] = 1;
        }       
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=i&&j<=len2; j++){                
                dp[i][j] += dp[i-1][j];
                if(S[i-1]==T[j-1]) dp[i][j] += dp[i-1][j-1];
            }
        }
        return dp[len1][len2];
    }
};
