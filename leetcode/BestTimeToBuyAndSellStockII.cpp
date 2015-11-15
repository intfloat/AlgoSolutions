#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = prices.size();
        int mn=0, mx=0;
        int res = 0;
        
        
        if(len <= 1)
            return 0;
        mn = prices[0], mx = prices[0];
        for(int i=1; i<len; i++){
            if(prices[i] < prices[i-1]){
                res += mx-mn;
                mx = mn = prices[i];
            }
            else
                mx = prices[i];
        }
        res += mx-mn;
        return res;
    }
};
