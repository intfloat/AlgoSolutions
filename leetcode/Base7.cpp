#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        bool negative = (num < 0);
        num = abs(num);
        string ret;
        while (num >= 7) {
            int lsb = num % 7;
            ret.push_back((char)('0' + lsb));
            num /= 7;
        }
        if (num > 0) {
            ret.push_back((char)('0' + num));
        }
        if (negative) {
            ret.push_back('-');
        }
        if (ret.empty()) {
            ret.push_back('0');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    Solution sol;
    cout << sol.convertToBase7(100) << endl;
    cout << sol.convertToBase7(-7) << endl;
    cout << sol.convertToBase7(0) << endl;
    return 0;
}
