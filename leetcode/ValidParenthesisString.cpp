#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        vector<int> star;
        vector<int> left;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                star.push_back(i);
            } else if (s[i] == '(') {
                left.push_back(i);
            } else {
                if (!left.empty()) left.pop_back();
                else star.push_back(i);
            }
        }

        for (int i = 0; i < star.size(); ++i) {
            left.push_back(star[i]);
        }
        sort(left.begin(), left.end());
        string ns;
        for (auto idx : left) {
            ns.push_back(s[idx]);
        }

        int s_cnt = 0, l_cnt = 0, r_cnt = 0;
        for (int i = 0; i < ns.size(); ++i) {
            if (ns[i] == ')') {
                if (s_cnt > 0) --s_cnt;
                else return false;
            } else if (ns[i] == '*') {
                if (l_cnt > 0) --l_cnt;
                else ++s_cnt;
            } else {
                s_cnt = 0;
                ++l_cnt;
            }
        }
        return l_cnt == 0;
    }
};

int main() {
    Solution sol;
    cout << sol.checkValidString("*****)*)(****") << endl;
    return 0;
}
