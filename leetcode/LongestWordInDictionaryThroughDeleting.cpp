#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(const string& s, const string& t) {
        if (s.size() < t.size()) {
            return false;
        }
        if (t.empty()) {
            return true;
        }
        int ptr = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == t[ptr]) ++ptr;
            if (ptr == t.size()) {
                return true;
            }
        }
        return false;
    }
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](const string& a, const string& b) {
            return a.size() > b.size() || (a.size() == b.size() && a < b);
        });
        for (string& t : d) {
            if (check(s, t)) {
                return t;
            }
        }
        return "";
    }
};

int main() {
    Solution sol;
    vector<string> d = {"a", "b", "c"};
    string s = "abpcplea";
    cout << sol.findLongestWord(s, d) << endl;
    return 0;
}