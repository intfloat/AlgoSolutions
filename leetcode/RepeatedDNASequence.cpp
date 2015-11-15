class Solution {
public:
    int get(char c) {
        if (c == 'A') return 0;
        if (c == 'G') return 1;
        if (c == 'C') return 2;
        if (c == 'T') return 3;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        map<int, int> m;
        if (s.size() <= 10) return res;
        int val = 0;
        for (int i = 0; i < 10; ++i) val = val * 4 + get(s[i]);
        m[val] = 1;
        for (int i = 10; i < s.size(); ++i) {
            val = (val * 4 + get(s[i])) % (1 << 20);
            if (m.find(val) == m.end()) m[val] = 1;
            else if (m[val] == 1) {
                ++m[val]; res.push_back(s.substr(i - 9, 10));
            }
            else ++m[val];
        }
        return res;
    }
};
