class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i = 1;
        while (i * i <= num) {
            if (i * i == num) {
                return true;
            }
            else {
                ++i;
            }
        }
        return false;
    }
};
