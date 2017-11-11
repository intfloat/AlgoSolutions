#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int zeros = 0, ones = 0, mask = (1 << i);
            for (auto n : nums) {
                if (mask & n) ++ones;
                else ++zeros;
            }
            res += ones * zeros;
        }
        return res;
    }
};

int main() {
    return 0;
}
