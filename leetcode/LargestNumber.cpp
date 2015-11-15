#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool cmp(const string& s1, const string& s2) {
    int maxlen = s1.size() * s2.size() / __gcd(s1.size(), s2.size());
    int ptr1, ptr2;    
    for (int i = 0; i < maxlen; ++i) {
        ptr1 = i % s1.size();
        ptr2 = i % s2.size();
        if (s1[ptr1] != s2[ptr2]) return s1[ptr1] > s2[ptr2];
    } 
    return false;
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> sn;
        stringstream ss;
        string t;
        for (int i = 0; i < num.size(); ++i) {
            ss.clear();
            ss << num[i];
            ss >> t;            
            sn.push_back(t);
        }
        sort(sn.begin(), sn.end(), cmp);        
        string res;
        for (int i = 0; i < sn.size(); ++i) {
            res += sn[i];
        }
        int i;
        for (i = 0; i < res.size(); ++i) {
            if (res[i] != '0') { res = res.substr(i, res.size() - i); break; }            
        }
        if (res.size() == 0 || i == res.size()) res = "0";
        return res;
    }
};
