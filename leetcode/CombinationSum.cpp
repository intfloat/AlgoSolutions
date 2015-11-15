#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> numbers;
    int len;

    vector<vector<int> > solve(int pos, int val) {
        vector<vector<int> > res;
        vector<int> row;
        res.clear(); row.clear();
        // one solution in this case
        if (val==0) {
            res.push_back(row);
            return res;
        }
        // there is no feasible solution
        if (pos>=len && val>0) {
            return res;
        }
        if (val < 0) {
            return res;
        }
        for (int c=0; ; c++) {
            int t = val - c*numbers[pos];
            if (t < 0) break;
            vector<vector<int> > cur = solve(pos+1, t);
            int s = cur.size();  
            for (int i=0; i<s; i++) {
                for (int j=0; j<c; j++) {
                    cur[i].push_back(numbers[pos]);
                }               
                if (cur[i].size() > 0)
                    res.push_back(cur[i]);
            }
        } // end for loop
        return res;
    } // end method solve

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {        
        vector<vector<int> > result;
        result.clear();
        sort(candidates.begin(), candidates.end(), greater<int>());
        len = unique(candidates.begin(), candidates.end())-candidates.begin();
        numbers.clear();
        for (int i=0; i<len; i++) {
            numbers.push_back(candidates[i]);           
        }        
        result = solve(0, target);
        return result;
    } // end method combinationSum
};
