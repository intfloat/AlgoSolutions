#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        for (auto& num : nums) {
            nums[abs(num) - 1] *= -1;
            if (nums[abs(num) - 1] > 0) {
                ret.push_back(abs(num));
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    for (auto& ans : sol.findDuplicates(nums)) {
        cout << ans << endl;
    }
    return 0;
}
