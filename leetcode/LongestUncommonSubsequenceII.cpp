#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    set<string> getSubstr(const string& s) {
        set<string> ret;
        int mx = 1 << s.size();
        for (int i = 1; i < mx; ++i) {
            string cur;
            for (int j = 0; j < (int)s.size(); ++j) {
                if ((1 << j) & i) {
                    cur.push_back(s[j]);
                }
            }
            ret.insert(cur);
        }
        return ret;
    }
public:
    int findLUSlength(vector<string>& strs) {
        int sz = strs.size();
        vector<set<string> > subs;
        for (int i = 0; i < sz; ++i) {
            subs.push_back(getSubstr(strs[i]));
        }
        vector<string> cand;
        for (int i = 0; i < sz; ++i) {
            for (auto it = subs[i].begin(); it != subs[i].end(); ++it) {
                cand.push_back(*it);
            }
        }
        sort(cand.begin(), cand.end(), [](const string& s1, const string& s2) {
            return s1.size() > s2.size();
        });
        cand.resize(unique(cand.begin(), cand.end()) - cand.begin());
        for (string& s : cand) {
            int cnt = 0;
            for (int i = 0; i < sz; ++i) {
                if (subs[i].find(s) != subs[i].end()) {
                    ++cnt;
                }
                if (cnt >= 2) break;
            }
            if (cnt < 2) {
                return s.size();
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"aabbcc","aabbcc","cb","abc","mmnnqq"};
    cout << sol.findLUSlength(strs) << endl;
    return 0;
}