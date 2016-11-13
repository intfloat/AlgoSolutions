typedef long long ll;
class Solution {
public:
    int findNthDigit(int n) {
        ll base = 1, cnt = 1;
        while (true) {
            ll cur = base * 9 * cnt;
            if (n > cur) {
                n -= cur;
                base *= 10;
                ++cnt;
            } else {
                if (n % cnt == 0) {
                    return (base + n / cnt - 1) % 10;
                } else {
                    ll num = base + (n - 1) / cnt;
                    n -= (n - 1) / cnt * cnt;
                    for (int i = 1; i < n; ++i) base /= 10;
                    return (num / base) % 10;
                }
            }
        }
    }
};
