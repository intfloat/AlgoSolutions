#include <bits/stdc++.h>
using namespace std;

vector<bool> isWin(1<<20);
vector<bool> isLose(1<<20);
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) {
            return false;
        }
        if (desiredTotal <= 0) {
            return true;
        }
        fill(isWin.begin(), isWin.begin() + (1 << maxChoosableInteger), false);
        fill(isLose.begin(), isLose.begin() + (1 << maxChoosableInteger), false);
        this->mx = maxChoosableInteger;
        return solve(0, desiredTotal);
    }
private:
    int mx;
    bool solve(int status, int total) {
        if (isWin[status]) return true;
        if (isLose[status]) return false;
        if (total <= 0) {
            isLose[status] = true;
            return false;
        }
        for (int i = 1; i <= this->mx; ++i) {
            if (!((1 << (i - 1)) & status)) {
                bool nt = solve(status | (1 << (i - 1)), total - i);
                if (!nt) {
                    isWin[status] = true;
                    return true;
                }
            }
        }
        isLose[status] = true;
        return false;
    }
};

int main() {
    Solution sol;
    cout << sol.canIWin(10, 11) << endl;
    for (int i = 10; i <= 160; ++i) {
        cout << i << " " << sol.canIWin(20, i) << endl;
    }
    return 0;
}
