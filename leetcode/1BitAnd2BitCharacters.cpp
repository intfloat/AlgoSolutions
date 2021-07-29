class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool res = true;
        int ptr = 0;
        while (ptr < bits.size()) {
            if (bits[ptr] == 0) {
                res = true;
                ++ptr;
            } else {
                res = false;
                ptr += 2;
            }
        }
        return res;
    }
};
