class Solution {
private:
    bool check(vector<double>& nums) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24.0) < 1e-6;
        }
        int sz = nums.size();
        bool ok = false;
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                vector<double> n_nums;
                for (int k = 0; k < sz; ++k) {
                    if (k != i && k != j) {
                        n_nums.push_back(nums[k]);
                    }
                }
                // a + b
                n_nums.push_back(nums[i] + nums[j]);
                ok = ok || check(n_nums);
                n_nums.pop_back();
                // a - b
                n_nums.push_back(nums[i] - nums[j]);
                ok = ok || check(n_nums);
                n_nums.pop_back();
                // b - a
                n_nums.push_back(nums[j] - nums[i]);
                ok = ok || check(n_nums);
                n_nums.pop_back();
                // a * b
                n_nums.push_back(nums[i] * nums[j]);
                ok = ok || check(n_nums);
                n_nums.pop_back();
                // a / b
                if (abs(nums[j]) > 1e-6) {
                    n_nums.push_back(nums[i] / nums[j]);
                    ok = ok || check(n_nums);
                    n_nums.pop_back();
                }
                // b / a
                if (abs(nums[i]) > 1e-6) {
                    n_nums.push_back(nums[j] / nums[i]);
                    ok = ok || check(n_nums);
                    n_nums.pop_back();
                }
                if (ok) return true;
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> d_nums;
        for (auto& n : nums) {
            d_nums.push_back(1.0 * n);
        }
        return this->check(d_nums);
    }
};
