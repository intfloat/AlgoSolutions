#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int sz = p.size();
        vector<vector<int> > dp(26, vector<int>(sz + 1, 0));
        vector<int> len(sz, 1);
        for (int i = 1; i < sz; ++i) {
            if (p[i] == p[i - 1] + 1 || (p[i] == 'a' && p[i - 1] == 'z')) {
                len[i] = len[i - 1] + 1;
            }
            dp[p[i] - 'a'][len[i]] = 1;
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = sz; j >= 0; --j) {
                if (dp[i][j]) {
                    res += j;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
