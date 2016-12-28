#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int median = nums[(int)nums.size() / 2];
        int res = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            res += abs(median - nums[i]);
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    cout << solution.minMoves2(nums) << endl;
    return 0;
}
