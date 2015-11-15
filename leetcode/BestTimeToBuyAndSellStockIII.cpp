#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = prices.size();
        if(len <= 1)
            return 0;
        
        int res = 0;
        vector<int> mn = prices;
        vector<int> forward = prices, backward = prices;
        for(int i=1; i<len; i++)
            mn[i] = min(mn[i-1], prices[i]);
            
        forward[0] = 0;
        for(int i=1; i<len; i++){
            forward[i] = max(forward[i-1], prices[i]-mn[i]);
            res = max(res, forward[i]);
        }
        backward[len-1] = 0;
        int mx = prices[len-1];     
        for(int i=len-2; i>=0; i--){
            mx = max(mx, prices[i]);
            backward[i] = max(backward[i+1], mx-prices[i]);
            res = max(res, backward[i]);
        }
        
        for(int i=1; i<len-1; i++)
            res = max(res, forward[i]+backward[i+1]);
        
        return res;
    }
};
