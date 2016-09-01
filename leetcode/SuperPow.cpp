const int MOD = 1337;
int fast_power(int num, int p) {
  int ret = 1, val = num;
  while (p > 0) {
    if (p & 1) ret = (ret * val) % MOD;
    val = (val * val) % MOD;
    p >>= 1;
  }
  return ret;
}
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        a %= MOD;
        if (a == 0) {
            return 0;
        }
        int res = 1;
        for (int i = 0; i < static_cast<int>(b.size()); ++i) {
            res = fast_power(res, 10) * fast_power(a, b[i]);
            res %= MOD;
        }
        return res;
    }
};
