class Solution {
private:
    int compute(const vector<int>& digits) {
        int res = 0;
        for (auto& d : digits) {
            res = res * 10 + d;
        }
        return res;
    }
public:
    int maximumSwap(int num) {
        vector<int> digits;
        int res = num;
        while (num > 0) {
            digits.push_back(num % 10);
            num = num / 10;
        }
        reverse(digits.begin(), digits.end());
        int sz = digits.size();
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                if (digits[i] >= digits[j]) {
                    continue;
                }
                swap(digits[i], digits[j]);
                int n_num = this->compute(digits);
                res = max(res, n_num);
                swap(digits[i], digits[j]);
            }
        }
        return res;
    }
};
