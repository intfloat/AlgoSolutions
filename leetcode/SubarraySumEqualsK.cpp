#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> cnt;
        int acc = 0;
        int res = 0;
        cnt[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            acc += nums[i];
            res += cnt[acc - k];
            ++cnt[acc];
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1};
    cout << solution.subarraySum(nums, 2) << endl;
    return 0;
}
