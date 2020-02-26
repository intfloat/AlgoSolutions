class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ptr = 0;
        int res = 0;
        while (ptr < flowerbed.size()) {
            if (flowerbed[ptr] == 1) {
                ++ptr;
                continue;
            }
            int start = ptr;
            while (ptr < flowerbed.size() && flowerbed[ptr] == 0) {
                ++ptr;
            }
            int slots = ptr - start;
            if (start > 0) --slots;
            if (ptr < flowerbed.size()) --slots;
            res += (max(slots, 0) + 1) / 2;
        }
        return res >= n;
    }
};
