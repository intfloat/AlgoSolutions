class Solution {
private:
    string int_to_s(long long number) {
        string ret = "";
        if (number < 0) {
            ret = "-";
            number = -number;
        }
        while (number > 0) {
            ret.push_back('0' + number % 10);
            number /= 10;
        }
        if (!ret.empty() && ret[0] == '-')
            reverse(ret.begin() + 1, ret.end());
        else reverse(ret.begin(), ret.end());
        if (ret.empty()) ret = "0";
        return ret;
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int ptr = 0, i;
        while (ptr < nums.size()) {
            for (i = ptr + 1; i < nums.size(); ++i) {
                if ((long long)nums[i] - (long long)nums[ptr] != i - ptr) {
                    break;
                }
            }
            if (i == ptr + 1) {
                result.push_back(int_to_s(nums[ptr]));
            }
            else {
                result.push_back(int_to_s(nums[ptr]) + "->" + int_to_s(nums[i - 1]));
            }
            ptr = i;
        }
        return result;
    }
};
