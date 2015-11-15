#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = A[0];      
        for(int i=1; i<n; i++){
            if(A[i-1] > 0)
                A[i] = A[i-1]+A[i];
            result = max(result, A[i]);
        }
        return result;
    }
};
