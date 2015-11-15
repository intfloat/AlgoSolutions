#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > res;
  int kk, nn;
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> record;
        record.clear();
        res.clear();
        if(n < k)      
            return res;
        kk=k, nn=n;
        dfs(1, kk, record);
        return res;
    }
    
    // use depth first search to solve this problem
    void dfs(int cur, int remain, vector<int> record){
        if(remain == 0){
            res.push_back(record);
            return;
        }
        if((nn-cur+1)<remain || cur>nn)
            return;
        if((nn-cur+1) == remain){
            for(int i=cur; i<=nn; i++)
                record.push_back(i);
            res.push_back(record);
            return;
        }       
        dfs(cur+1, remain, record);
        record.push_back(cur);
        dfs(cur+1, remain-1, record);
        return;
    }
};
