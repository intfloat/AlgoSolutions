// SingleNumberII.cpp
class Solution {
public:
    // a very clever idea
    int singleNumber(int A[], int n) {
        int zero = 0, one = 0, two = 0;         
        for(int i=0; i<n; i++){
            // appear zero time in modulo 3 group
            zero = ~(one|two);
            int tone = one;
            // appear one time in modulo 3 group
            one = (one&(~A[i]))|(zero&A[i]);    
            // appear two times in modulo 3 group       
            two = (two&(~A[i]))|(tone&A[i]);
        }
        return one;
    }
};
