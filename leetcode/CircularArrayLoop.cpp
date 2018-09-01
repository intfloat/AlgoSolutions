#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int sz = nums.size();
        vector<bool> visited(sz, false);
        for (int i = 0; i < sz; ++i) {
            nums[i] = nums[i] % sz;
            visited[i] = (nums[i] == 0);
        }
        set<int> current;
        for (int i = 0; i < sz; ++i) {
            if (visited[i]) continue;
            int ptr = i;
            current.insert(ptr);
            while (true) {
                ptr = (ptr + nums[ptr] + sz) % sz;
                if (current.find(ptr) != current.end()) {
                    break;
                } else if (visited[ptr]
                    || (nums[i] > 0 && nums[ptr] < 0)
                    || (nums[i] < 0 && nums[ptr] > 0)) {
                    for (auto idx : current) {
                        visited[idx] = true;
                    }
                    current.clear();
                    break;
                } else {
                    current.insert(ptr);
                }
            }
            if (current.size() > 1) {
                return true;
            }
            for (auto idx : current) {
                visited[idx] = true;
            }
            current.clear();
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, -1, 1, 2, 2};
    cout << sol.circularArrayLoop(nums) << endl;
    nums = {-1, 2};
    cout << sol.circularArrayLoop(nums) << endl;
    return 0;
}