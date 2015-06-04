#include <bits/stdc++.h>
using namespace std;

class Cyclemin {
public:
    string bestmod(string, int);
};

string Cyclemin::bestmod(string s, int k) {
    int sz = s.size();
    string res = s;
    string mn = "";
    for (int i = 0; i < sz; ++i) mn += 'a';
    for (int i = 0; i < s.size(); ++i) {
        string cur = s;
        int up = k;
        for (int j = 0; j < up; ++j) {
            int pos = (i + j) % sz;
            if (cur[pos] == 'a') ++up;
            else cur[pos] = 'a';
            if (up >= s.size()) return mn;
        }
        vector<string> arr;
        for (int j = 0; j < cur.size(); ++j) arr.push_back(cur.substr(j, cur.size() - j) + cur.substr(0, j));
        res = min(res, *min_element(arr.begin(), arr.end()));
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
