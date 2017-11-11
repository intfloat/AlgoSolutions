class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int ptr = 0;
        while (ptr < nums.size()) {
            if (nums[ptr] == 1) {
                int end = ptr + 1;
                while (end < nums.size() && nums[end] == 1) ++end;
                res = max(res, end - ptr);
                ptr = end + 1;
            } else {
                ++ptr;
            }
        }
        return res;
    }
};
