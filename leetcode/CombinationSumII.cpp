#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> numbers;
    map<int, int> m;
    int len;

    vector<vector<int> > solve(int pos, int val) {
        vector<vector<int> > res;
        vector<int> row;
        res.clear(); row.clear();
        if (val == 0) {
            res.push_back(row);
            return res;
        }
        if (pos>=len && val>0) {
            return res;
        }
        if (val < 0) {
            return res;
        }

        int upper = m[numbers[pos]];
        for (int c=0; c<=upper; c++) {
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

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        m.clear();
        for (int i=0; i<num.size(); i++)
            m[num[i]]++;
        sort(num.begin(), num.end(), greater<int>());
        len = unique(num.begin(), num.end()) - num.begin();
        numbers.clear();        
        for (int i=0; i<len; i++) {
            numbers.push_back(num[i]);          
        }       
        return solve(0, target);
    } // end method combinationSum2
};
