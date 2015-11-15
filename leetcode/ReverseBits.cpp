class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            if ((1 << i) & n) res |= (1 << (31 - i));
        }
        return res;
    }
};
