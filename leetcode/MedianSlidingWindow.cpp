#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        if (nums.empty()) {
            return res;
        }
        multiset<int> left, right;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (left.empty() || nums[i] <= *left.rbegin()) {
                left.insert(nums[i]);
            } else {
                right.insert(nums[i]);
            }
            if (i >= k) {
                auto it = left.find(nums[i - k]);
                if (it != left.end()) {
                    left.erase(it);
                } else {
                    right.erase(right.find(nums[i - k]));
                }
            }
            int expected_size = (left.size() + right.size()) / 2;
            while ((int)right.size() < expected_size) {
                right.insert(*left.rbegin());
                auto it = left.end();
                --it;
                left.erase(it);
            }
            while ((int)right.size() > expected_size) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
            if (i < k - 1) {
                continue;
            }
            if (k % 2 == 1) {
                res.push_back(*left.rbegin() * 1.0);
            } else {
                res.push_back(*left.rbegin() * 0.5 + *right.begin() * 0.5);
            }
        }
        return res;
    }
};
