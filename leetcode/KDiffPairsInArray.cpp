#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ptr = 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - 1 >= 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            ptr = max(i + 1, ptr);
            while (ptr < nums.size() && nums[ptr] < nums[i] + k) {
                ++ptr;
            }
            ret += (ptr < nums.size() && nums[ptr] == nums[i] + k);
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 1, 5, 4};
    cout << solution.findPairs(nums, 0) << endl;
    return 0;
}