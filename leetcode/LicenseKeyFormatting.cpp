#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        reverse(S.begin(), S.end());
        string res;
        int cur = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '-') {
                continue;
            } else if (S[i] <= 'z' && S[i] >= 'a') {
                res.push_back(S[i] - 'a' + 'A');
            } else {
                res.push_back(S[i]);

            }
            ++cur;
            if (cur == K) {
                res.push_back('-');
                cur = 0;
            }
        }
        if (res.back() == '-') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
