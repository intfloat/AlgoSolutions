#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;

class Solution {
public:
    string reverseStr(string s, int k) {
        int ptr = 0;
        while (ptr < (int)s.size()) {
            int sz = min(k, (int)s.size() - ptr);
            reverse(s.begin() + ptr, s.begin() + ptr + sz);
            ptr += 2 * k;
        }
        return s;
    }
};

int main() {
    Solution solution;
    cout << solution.reverseStr("abcdefg", 2) << endl;
    return 0;
}