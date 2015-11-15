// WordBreak.cpp
class Solution {
public: 
    // easy stuff
    bool wordBreak(string s, unordered_set<string> &dict) {
        bool dp[2000]; 
        int len = s.size();     
        memset(dp, false, sizeof(dp));
        for(int i=0; i<len; i++){
            string cur = "";
            if(dict.find(s.substr(0, i+1))!=dict.end()){
                dp[i] = true;
                continue;
            }
            for(int j=i; j>0; j--){
                cur = s[j]+cur;
                if(dp[j-1] && dict.find(cur)!=dict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len-1];
    }
};