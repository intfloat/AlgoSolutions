#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return false;
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] == 0 && nums[i] == 0) {
                return true;
            }
        }
        if (k == 0 || k == INT_MIN) {
            return false;
        }
        if (k < 0) k = -k;
        vector<int> rem;
        int remainder = 0;
        for (int& n : nums) {
            remainder = (remainder + n) % k;
            rem.push_back(remainder);
        }
        set<int> seen;
        for (int i = 1; i < nums.size(); ++i) {
            if (i - 2 < 0) seen.insert(0);
            else seen.insert(rem[i - 2]);
            if (seen.find(rem[i]) != seen.end()) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {23, 3, 6, 4, 7};
    int k = 7;
    cout << sol.checkSubarraySum(nums, k) << endl;
    return 0;
}