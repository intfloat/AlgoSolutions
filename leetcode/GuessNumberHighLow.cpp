// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (guess(mid) < 0) r = mid - 1;
            else if (guess(mid) > 0) l = mid + 1;
            else l = r = mid;
        }
        return l;
    }
};
