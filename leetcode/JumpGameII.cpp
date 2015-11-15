#include <limits.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(n==1)      
            return 0;
        
        int *dp = new int[n+1];
        for(int i=0; i<n; i++)
            dp[i] = INT_MAX;
        int ptr = 1;
        dp[0] = 0;
        for(int i=0; i<n; i++){
            // unreachable
            if(i >= ptr)
                return -1;
            if(A[i]+i+1 > ptr){             
                // update results
                for(int j=ptr; j<=min(A[i]+i, n-1); j++)
                    dp[j] = min(dp[j], dp[i]+1);
                ptr = A[i]+i+1;
            }
            if(ptr >= n)
                return dp[n-1];
        }
        // unreachable
        return -1;
    }
};
