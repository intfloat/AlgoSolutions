class Solution {
public:
    int reachNumber(int target) {
        if (target < 0) {
            target = -target;
        }
        int val = 0;
        for (int i = 1; ; ++i) {
            val += i;
            if (val < target) {
                continue;
            }
            int rem = val - target;
            if (rem % 2 == 0) {
                return i;
            }
        }
        return -1;
    }
};
