#include <string>
#include <algorithm>

using namespace std;


// use dynamic programming to solve this problem
class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string str1 = "#"+word1;
        string str2 = "#"+word2;
        int len1 = str1.size();
        int len2 = str2.size();
        int **dp = new int*[len1];
        for(int i=0; i<len1; i++)
            dp[i] = new int[len2];
        
        for(int i=0; i<len1; i++)
            dp[i][0] = i;
        for(int i=0; i<len2; i++)
            dp[0][i] = i;
        for(int i=1; i<len1; i++)
        for(int j=1; j<len2; j++){
            dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1;
            if(str1[i]==str2[j])
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            else
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
        }
        return dp[len1-1][len2-1];
    }
};
