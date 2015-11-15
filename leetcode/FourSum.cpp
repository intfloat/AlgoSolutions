#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <ctime>

using namespace std;

// a O(N^3) solution using hash map, 408 ms used
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        set<vector<int> > result;
        vector<int> row;
        vector<vector<int> > g;
        g.clear();
        result.clear();        
        map<int, pair<int, int> > m;
        m.clear();
        sort(num.begin(), num.end());
        int len = num.size();
        if(len < 4) return g;
        int mn = 0;
        for (int i=0; i<4; i++) mn += num[i];
        if (target < mn) return g;
        int mx = 0;
        for (int i=len-4; i<len; i++) mx += num[i];
        if (target > mx) return g;

        for (int i=0; i<len; i++) {
            if (m.find(num[i]) == m.end()) {
                m[num[i]] = make_pair(i, i);
            }
            else m[num[i]].second = i;
        }
    
        int total = 0;    
        for (int i=0; i<len-3; i++)
        for (int j=i+1; j<len-2; j++)
        for (int k=j+1; k<len-1; k++) {
            int remain = target-(num[i]+num[j]+num[k]);
            if (remain < num[k+1]) break;
            if (m.find(remain) == m.end()) continue;
            if (m[remain].second <= k) continue;
            row.clear();
            row.push_back(num[i]);
            row.push_back(num[j]);
            row.push_back(num[k]);
            row.push_back(remain);
            result.insert(row);         
        } // end for loop

        
        set<vector<int> >::iterator it;
        for (it=result.begin(); it!=result.end(); it++)
            g.push_back(*it);
        return g;
    } // end method fourSum
};
