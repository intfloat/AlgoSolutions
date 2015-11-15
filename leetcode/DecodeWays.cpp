#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(s.size() == 0)
            return 0;
        
        s = '$'+s;
        int len = s.size();
        int *dp = new int[len+5];
        if(s[1]=='0')
            return 0;
        dp[0] = 1; dp[1] = 1;
        for(int i=2; i<len; i++){
            if(s[i]=='0'){
                if(s[i-1]!='1' && s[i-1]!='2')
                    return 0;
                dp[i] = dp[i-2];
            }
            else{
                int num = (s[i-1]-'0')*10 + (s[i]-'0');
                if(num<10 || num>26)
                    dp[i] = dp[i-1];
                else
                    dp[i] = dp[i-1]+dp[i-2];
            }
        }
        return dp[len-1];
    }
};
