#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = prices.size();
        int res = 0;
        int mx = 0;
        for(int i=len-1; i>=0; i--){
            mx = max(mx, prices[i]);
            res = max(res, mx-prices[i]);
        }

        return res;
    }
};
