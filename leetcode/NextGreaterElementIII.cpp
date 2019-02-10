#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<char> s;
        while (n > 0) {
            s.push_back((char)('0' + n % 10));
            n /= 10;
        }
        if (s.size() <= 1) return -1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] < s[i - 1]) {
                for (int j = 0; j < i; ++j) {
                    if (s[j] > s[i]) {
                        swap(s[i], s[j]);
                        sort(s.begin(), s.begin() + i, greater<char>());
                        reverse(s.begin(), s.end());
                        ll res = 0;
                        for (int k = 0; k < s.size(); ++k) {
                            res = res * 10 + (s[k] - '0');
                        }
                        if (res <= INT_MAX) return (int)res;
                        else return -1;
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    cout << solution.nextGreaterElement(12) << endl;
    cout << solution.nextGreaterElement(21) << endl;
    // 1421134
    cout << solution.nextGreaterElement(1414321) << endl;
    return 0;
}