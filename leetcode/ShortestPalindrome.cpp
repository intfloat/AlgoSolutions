class Solution {
public:
    string shortestPalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int n = s.size();
        for (int l = n; l >= 0; --l) {
            if(s.substr(0, l) == s2.substr(n - l))
                return s2.substr(0, n - l) + s;
        }
        assert(false);
    }
};
