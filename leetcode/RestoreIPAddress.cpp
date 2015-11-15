#include <vector>
#include <string>
#include <iostream>
using namespace std;

// i think back tracing can solve this problem
class Solution {
public:
    vector<string> result;
    vector<int> single;
    int len;
    string str;
    vector<string> restoreIpAddresses(string s) {
        str = s;
        len = s.size();
        result.clear(); single.clear();
        dfs(0, 0);
        return result;
    }
    
    // just simple depth first search
    void dfs(int pos, int val){
        //if(val > 255) return;
        if(pos == len){
            if(single.size() != 4) return;
            string s = str.substr(0, single[0]+1);
            if(s.size()>1 && s[0]=='0') return;
            for(int i=1; i<single.size(); i++){ 
                string t = str.substr(single[i-1]+1, single[i]-single[i-1]);
                if(t.size()>1 && t[0]=='0') return;
                s+="."+t;
            }
            result.push_back(s);
            return;
        }
        if((10*val+str[pos]-'0') > 255) return;
        if(single.size() >= 4) return;
        // insert a period
        single.push_back(pos);
        dfs(pos+1, 0);
        single.erase(single.end()-1);
        // continue
        dfs(pos+1, 10*val+str[pos]-'0');
        return;
    }// end method dfs
};

