class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        res[0] = 0;
        for (int i = 1; i <= num; ++i) {
            if (i & 1) {
                res[i] = 1 + res[i / 2];
            }
            else {
                res[i] = res[i / 2];
            }
        }
        return res;
    }
};
