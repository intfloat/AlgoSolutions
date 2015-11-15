class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while (n > 0) {
            --n;
            char c = 'A' + (n % 26);
            res = c + res;
            n /= 26;
        }
        return res;
    }
};
