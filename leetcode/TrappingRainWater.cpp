class Solution {
public:
    // floodfill algorithm
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int res = 0;
        int left=0, right=n-1;
        while(left < right){
            if(A[left]<A[right]){
                int ptr = left+1;
                while(ptr<right && A[ptr]<=A[left]){
                    res += A[left]-A[ptr];
                    ptr++;
                }
                left = ptr;
            }
            else{
                int ptr = right-1;
                while(ptr>left && A[ptr]<=A[right]){
                    res += A[right]-A[ptr];
                    ptr--;
                }
                right = ptr;
            }
        }
        return res;
    }
};
