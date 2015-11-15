class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) {
            return 0;
        }
        int res = 0;
        int m = 1;
        while (n / m >= 10) {
            m *= 10;
        }
        while (m > 0) {
            int a = n / m;
            int b = n % m;
            if (a % 10 == 0) {
                res += (a / 10) * m;
            }
            else if (a % 10 == 1) {
                res += b + 1 + (a / 10) * m;
            }
            else {
                res += (1 + a / 10) * m;
            }
            m /= 10;
        }
        return res;
    }
};
