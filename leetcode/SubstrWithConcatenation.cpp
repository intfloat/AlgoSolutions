// SubstrWithConcatenation.cpp

#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    // direct implementation
    // 1808 ms... anyway, it is accepted...
    vector<int> findSubstring(string S, vector<string> &L) {
        map<string, int> dict, cur;
        dict.clear(); cur.clear();
        int len = S.size();
        for (int i=0; i<L.size(); i++) dict[L[i]]++;
        vector<int> res;
        res.clear();
        if (len == 0) return res;
        int row = L[0].size();
        int num = L.size();
        for (int i=0; i<=len-row*num; i++) {
            cur.clear();
            int c = 0;
            for (int j=i; ; j+=row) {
                string s = S.substr(j, row);
                // invalid case
                if (dict.find(s) == dict.end()) break;
                cur[s]++;
                if (cur[s] > dict[s]) break;
                ++c;
                if (c == num) {
                    res.push_back(i);
                    break;
                }
            } // end inner for loop
        } // end external for loop
        return res;
    } // end method findSubstring
};

