#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(divisor == 0)
            return NULL;
        
        long long num = abs((long long)dividend), de = abs((long long)divisor);
        int result = 0;
        while(num >= de){
        int k = 0;
            while((de<<k) <= num)
                k++;
            k--;
            result += (1<<k);
            num -= (de<<k);
        }
        
        if(dividend<0 && divisor>0)
            result = -result;
        else if(dividend>0 && divisor<0)
            result = -result;
        return result;
    }
};
