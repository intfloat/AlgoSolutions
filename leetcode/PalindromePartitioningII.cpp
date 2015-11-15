// PalindromePartitioningII.cpp

#include <string.h>
#include <string>

using namespace std;

// the key to solve this problem is to come up with 
// an efficient O(N^2) dynamic programming algorithm.
class Solution {
public:
    bool pal[1500][1500];
    int len;
    int dp[2000];

    void preprocess(string s){
        for(int i=0; i<len; i++){
            int left = i;
            int right = i;
            while(left>=0 && right<len && s[left]==s[right]){
                pal[left][right] = true;
                left--; right++;
            }
        }
        for(int i=0; i<len; i++){
            int left = i;
            int right = i+1;
            while(left>=0 && right<len && s[left]==s[right]){
                pal[left][right] = true;
                left--; right++;
            }
        }
        return;
    }

    int minCut(string s) {
        len = s.size();
        for(int i=0; i<len; i++)
            for(int j=i; j<len; j++)
                pal[i][j] = false;
        preprocess(s);
        for(int i=0; i<len; i++) dp[i] = len+10;
        dp[0] = 0;
        for(int i=1; i<len; i++){
            if(pal[0][i]){ dp[i]=0; continue; }
            for(int j=i; j>0; j--){             
                if(pal[j][i]) dp[i] = min(dp[i], dp[j-1]+1);
            }
        }
        return dp[len-1];
    }
};