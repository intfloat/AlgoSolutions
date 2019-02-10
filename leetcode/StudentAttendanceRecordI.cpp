#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;

class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0;
        int late = 0;
        FOR(i, s.size()) {
            if (s[i] != 'L') late = 0;
            if (s[i] == 'A') ++absent;
            else if (s[i] == 'L') ++late;
            if (absent > 1 || late > 2) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.checkRecord("PPALLP") << endl;
    cout << solution.checkRecord("PPALLL") << endl;
    return 0;
}