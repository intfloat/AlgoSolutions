#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        bool inSeg = false;
        for (auto& ch : s) {
            if (ch != ' ') {
                inSeg = true;
            } else if (ch == ' ' && inSeg) {
                ++cnt;
                inSeg = false;
            }
        }
        cnt += inSeg;
        return cnt;
    }
};

int main() {
    Solution sol;
    cout << sol.countSegments("Hello, my name is John") << endl;
    return 0;
}
