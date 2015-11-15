#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len1=s1.size(), len2=s2.size(), len3=s3.size();
        if((len1+len2) != len3)      
            return false;
            
        if(len1 == 0)
            return s2==s3;
        else if(len2 == 0)
            return s1==s3;
        
        bool dp[200][200];
        dp[0][0] = true;
        
        for(int i=1; i<=len1; i++)
            dp[i][0] = dp[i-1][0] && (s1[i-1]==s3[i-1]);
        for(int i=1; i<=len2; i++)
            dp[0][i] = dp[0][i-1] && (s2[i-1]==s3[i-1]);
            
        for(int i=1; i<=len1; i++)
        for(int j=1; j<=len2; j++){                 
            dp[i][j] = (s1[i-1]==s3[i+j-1] && dp[i-1][j]) || (s2[j-1]==s3[i+j-1] && dp[i][j-1]);            
        }
        
        return dp[len1][len2];
    }
};
