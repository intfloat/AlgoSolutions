#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        string digits = "122";
        int ptr = 2, filler = 1;
        while (digits.size() < n) {
            for (int i = 0; i < digits[ptr] - '0'; ++i) {
                digits.push_back('0' + filler);
            }
            ++ptr;
            filler = (filler == 1) ? 2 : 1;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += digits[i] == '1';
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.magicalString(7) << endl;
    return 0;
}
