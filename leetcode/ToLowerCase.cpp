class Solution {
public:
    string toLowerCase(string s) {
        string res;
        for (int i = 0; i < (int)s.size(); ++i) {
            if ('A' <= s[i] && s[i] <= 'Z') {
                res.push_back(s[i] - 'A' + 'a');
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
