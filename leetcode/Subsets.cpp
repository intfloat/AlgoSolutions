#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        vector<int> record;
        res.clear();
        int len = S.size();
        int low=0, upp=(1<<len);
        
        // I think bit mask is more convenient than dfs
        sort(S.begin(), S.end());
        for(int i=low; i<upp; i++){
            record.clear();
            for(int j=0; j<len; j++){
                if(((1<<j)&i) > 0)
                    record.push_back(S[j]);
            }
            res.push_back(record);
        }
        return res;
    }
};
