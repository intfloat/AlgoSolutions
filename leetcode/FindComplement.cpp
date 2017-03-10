#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        for (int i = 31; i >= 0; --i) {
            if ((1 << i) & num) {
                int res = 0;
                for (int j = i - 1; j >= 0; --j) {
                    if (!((1 << j) & num)) {
                        res += (1 << j);
                    }
                }
                return res;
            }
        }
        return 0;
    }
};

int main() {
    return 0;
}
