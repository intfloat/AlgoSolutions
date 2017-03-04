#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        for (auto& num : nums) {
            if (nums[abs(num) - 1] > 0) {
                nums[abs(num) - 1] *= -1;
            }
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] > 0) {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};

int main() {
    return 0;
}
