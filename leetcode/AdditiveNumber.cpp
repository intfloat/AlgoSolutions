class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.size();
        for (int n1 = 1; n1 < len; ++n1) {
            for (int n2 = 1; n1 + n2 + max(n1, n2) <= len; ++n2) {
                if (check(n1, n2, num)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool check(int n1, int n2, string& num) {
        int l = 0, mid = n1, r = n1 + n2;
        if ((mid > l + 1 && num[l] == '0') || (r > mid + 1 && num[mid] == '0')) {
            return false;
        }
        while (r < (int)num.size()) {
            string sm = ll_to_s(s_to_ll(num, l, mid) + s_to_ll(num, mid, r));
            if (sm.size() <= num.size() - r && sm == num.substr(r, sm.size())) {
                l = mid; mid = r; r = mid + sm.size();
            }
            else {
                return false;
            }
        }
        return true;
    }
    long long s_to_ll(string& num, int l, int r) {
        long long ret = 0;
        for (int i = l; i < r; ++i) {
            ret = (ret * 10) + (num[i] - '0');
        }
        return ret;
    }
    string ll_to_s(long long num) {
        string ret;
        while (num > 0) {
            ret.push_back((char)('0' + num % 10));
            num /= 10;
        }
        reverse(ret.begin(), ret.end());
        if (ret.empty()) {
            ret.push_back('0');
        }
        return ret;
    }
};
