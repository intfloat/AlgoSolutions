class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // just xor all of the numbers
        for(int i=1; i<n; i++)
            A[i] = A[i]^A[i-1];
        return A[n-1];
    }
};
