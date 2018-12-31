#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1;
        while (right > left) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 0 && nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else if (mid % 2 == 0 && nums[mid] != nums[mid + 1]) {
                right = mid;
            } else if (mid % 2 == 1 && nums[mid] != nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return nums[left];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,3,7,7,10,11,11};
    cout << solution.singleNonDuplicate(nums) << endl;
    return 0;
}