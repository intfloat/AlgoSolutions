#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(n==1)
            return true;
        
        int ptr = 1;
        for(int i=0; i<n; i++){
            if(i >= ptr)
                return false;
            ptr = max(ptr, i+A[i]+1);
            if(ptr >= n)
                return true;
        }
        return false;
    }
};
