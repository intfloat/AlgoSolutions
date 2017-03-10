#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<int> cnt(300, 0);
        for (int i = 0; i < (int)s.size(); ++i) {
            ++cnt[s[i]];
        }
        vector<pair<int, char> > st_cnt;
        for (int i = 0; i < (int)cnt.size(); ++i) {
            if (cnt[i] > 0) {
                st_cnt.push_back({cnt[i], (char)i});
            }
        }
        sort(st_cnt.begin(), st_cnt.end(), greater<pair<int, char> >());
        string ret;
        for (int i = 0; i < (int)st_cnt.size(); ++i) {
            for (int j = 0; j < st_cnt[i].first; ++j) {
                ret.push_back(st_cnt[i].second);
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    cout << sol.frequencySort("tree") << endl;
    cout << sol.frequencySort("cccaaa") << endl;
    cout << sol.frequencySort("Aabb") << endl;
    return 0;
}
