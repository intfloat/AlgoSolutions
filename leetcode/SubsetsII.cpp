#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


// use backtrace technique to solve this problem
class Solution {
public:
    vector<pair<int, int> >  v;
    vector<vector<int> > res;
    int len;
    
    void dfs(int step, vector<int> record){
        if(step == len){
            res.push_back(record);
            return;
        }
        for(int i=0; i<=v[step].second; i++){
            for(int j=0; j<i; j++)
                record.push_back(v[step].first);
            dfs(step+1, record);
            for(int j=0; j<i; j++)
                record.erase(record.begin()+record.size()-1);
        }
        return;
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        v.clear(); res.clear();
        vector<int> record;
        record.clear();         
        if(S.size() == 0)
            return res;
        v.push_back(make_pair(S[0], 1));
        
        for(int i=1; i<S.size(); i++){
            if(S[i] == S[i-1])
                v[v.size()-1].second++;
            else
                v.push_back(make_pair(S[i], 1));
        }
        
        len = v.size();
        dfs(0, record);
        
        return res;
    }
};
