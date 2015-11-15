// ScrambleString.cpp
class Solution {
public:
    // use divide and conquer technique.
    // the key is to notice, if two parts have been swapped,
    // then the relative order will never change on the whole
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        string t1 = s1, t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) return false;
        int len = s1.size();        
        for (int i=0; i<len-1; i++) {
            t1 = s1.substr(0, i+1);
            t2 = s2.substr(0, i+1);
            sort(t1.begin(), t1.end());
            sort(t2.begin(), t2.end());
            bool ok = false;
            if (t1 == t2) {
                ok = isScramble(s1.substr(0, i+1), s2.substr(0, i+1))
                    && isScramble(s1.substr(i+1, len-i-1), s2.substr(i+1, len-i-1));
                if (ok) return true;
            }
            t2 = s2.substr(len-i-1, i+1);
            sort(t2.begin(), t2.end());
            if (t1 == t2) {
                ok = isScramble(s1.substr(0, i+1), s2.substr(len-i-1, i+1))
                && isScramble(s1.substr(i+1, len-i-1), s2.substr(0, len-i-1));
                if (ok) return true;
            }
        }
        return false;
    }
};
