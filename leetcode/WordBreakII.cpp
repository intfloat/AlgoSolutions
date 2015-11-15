// WordBreakII.cpp
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        int len = s.size();
        res.clear();
        // use dynamic programming technique to solve this problem                  
        if(dict.find(s)!=dict.end()){
            res.push_back(s);
        }
        string cur = "";
        for(int j=len-1; j>0; j--){
            cur = s[j]+cur;
            if(dict.find(cur)!=dict.end()){
                // use recursion to avoid unnecessary computation
                // and memory limit exceeded error
                vector<string> prev = wordBreak(s.substr(0, j), dict);
                for(int k=0; k<prev.size(); k++){
                    string t = prev[k];
                    t += " "+cur;
                    res.push_back(t);
                }
            }// end if clause
        }// end for loop
        return res;
    }
};